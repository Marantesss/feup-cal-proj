#ifndef ECOPONTO_WASTE_PICKUP_GRAPHSEARCHALGORITHM_H
#define ECOPONTO_WASTE_PICKUP_GRAPHSEARCHALGORITHM_H

#include "../Graph/Node.h"
#include "../Graph/Graph.h"
#include "../Utils/defs.h"
#include <unordered_set>

class GraphSearchAlgorithm {
protected:
    const Graph &graph;
    NodeHashTable nodeHashTable;

    bool isVisited(const Node &node) const;

public:
    explicit GraphSearchAlgorithm(const Graph &graph);

    virtual NodeHashTable performSearch(unsigned int start) = 0;

    virtual bool isPossible(unsigned int start, unsigned int end) = 0;
};


#endif //ECOPONTO_WASTE_PICKUP_GRAPHSEARCHALGORITHM_H
