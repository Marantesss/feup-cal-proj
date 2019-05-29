#ifndef ECOPONTO_WASTE_PICKUP_NEARESTNEIGHBOUR_H
#define ECOPONTO_WASTE_PICKUP_NEARESTNEIGHBOUR_H

#include "../Graph/Node.h"
#include "../Graph/Graph.h"
#include "../Utils/defs.h"
#include "DFS.h"
#include "Dijkstra.h"
#include "Graph/Container.h"

using namespace std;


class NearestNeighbour {
private:
    const Graph &graph;
    ContainerHashTable containerHashTable;
    DFS dfs;
    vector<unsigned int> visitOrder;
    vector<unsigned int> lastSolution;

    Node start;
    Node end;
    unsigned int visitOrderSize;
    double solutionTotalCost = DBL_MAX;

    void verifyValidNodes(const vector<Container> &containers);

    void findBestVisitOrder(Node &start, Node &end);

    Node getClosestNode(Node &node, ContainerHashTable otherNodes);

    void addNodeVisitOrder(Node &node);

    void removeNodeVisitOrder(Node &node);

    void buildSolution();

    void append_vector(vector<unsigned int> &v1, vector<unsigned int> &v2);

    void initDS();

public:
    explicit NearestNeighbour(const Graph &graph);

    vector<unsigned int> calculatePath(unsigned int startId, unsigned int finishId, const vector<Container> &containers);

    vector<unsigned int> getVisitOrder();

    double getSolutionWeight()const;



};


#endif //ECOPONTO_WASTE_PICKUP_NEARESTNEIGHBOUR_H
