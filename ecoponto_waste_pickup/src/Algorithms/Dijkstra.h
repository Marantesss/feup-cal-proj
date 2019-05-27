#ifndef ECOPONTO_WASTE_PICKUP_DIJKSTRA_H
#define ECOPONTO_WASTE_PICKUP_DIJKSTRA_H

#include <set>
#include "Graph/Graph.h"
#include "Graph/DijNode.h"

class Dijkstra {
    // ---- Data Structures
    const Graph &graph;
    set<DijNode > pQueue;
    DijNodeHashTable checkedDijNodes;

    // ---- Variables for current calculation
    Node finishNode;
    Node startNode;
    double solutionTotalCost = DBL_MAX;
    DijNode topDNode;

    vector<unsigned int> lastSolution;

    // Sets all queue's elements to the nodes in the graph and then puts the first node on top
    virtual void populateQueue();

    // Check if the current node has been analised (if it has, it will be in checkedDNodes)
    bool isCheckedNode(unsigned int nodeId) const;

    // Updates a DNode in the pQueue
    void updateNodeOnQueue(const DijNode & currDNode, set<DijNode> & queue);

    // Takes the finish node that should be on top of the queue and creates a path from recurrent previous nodes
    virtual void buildPath();

    // Goes through queue's top node's children and updates them in the queue
    virtual void updateQueue();

    // Checks if the optimal solution has been found (if final node is on top of the queue)
    virtual bool foundOptimalSolution();

    // Retrived a node in checkedNodes by its id
    DijNode getCheckedNode(u_int id) const;

public:

    explicit Dijkstra(const Graph &graph);

    // Calculates optimal path between two nodes
    vector<unsigned int> & calcOptimalPath(unsigned int startNodeId, unsigned int finishNodeId);

    // Returns the solution weight, if there is a solution at the present moment
    double getSolutionWeight() const;

    // Verifies if there is a solution at the present moment
    bool foundSolution() const;
};


#endif //ECOPONTO_WASTE_PICKUP_DIJKSTRA_H
