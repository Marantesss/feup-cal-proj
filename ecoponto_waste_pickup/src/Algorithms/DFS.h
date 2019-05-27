#ifndef ECOPONTO_WASTE_PICKUP_DFS_H
#define ECOPONTO_WASTE_PICKUP_DFS_H


#include "GraphSearchAlgorithm.h"

class DFS : public GraphSearchAlgorithm{
private:
    void visitNode(const Node &node);

    bool visitNodeCondition(const Node &node, const Node &end);

public:
    DFS(const Graph &graph);

    NodeHashTable performSearch(unsigned int start) override;

    bool isPossible(unsigned int start, unsigned int end) override;
};


#endif //ECOPONTO_WASTE_PICKUP_DFS_H
