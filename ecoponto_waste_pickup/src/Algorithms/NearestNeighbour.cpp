#include "NearestNeighbour.h"

NearestNeighbour::NearestNeighbour(const Graph &graph) : graph(graph), dfs(graph) {}

void NearestNeighbour::initDS() {
    visitOrder.clear();
    lastSolution.clear();
    nodeHashTable.clear();
}

void NearestNeighbour::verifyValidNodes(const vector<unsigned int> &pois) {
    for (unsigned int id: pois) {
        if (id != this->start.getId() && id != this->end.getId())
            this->nodeHashTable.insert(this->graph.getNode(id));
    }
}

void NearestNeighbour::addNodeVisitOrder(Node &node) {
    this->visitOrder.push_back(node.getId());
    this->nodeHashTable.erase(node);
}

void NearestNeighbour::removeNodeVisitOrder(Node &node) {
    this->visitOrder.pop_back();
    this->nodeHashTable.insert(node);
}

Node NearestNeighbour::getClosestNode(Node &node, const NodeHashTable otherNodes) {
    Node closestNode = *otherNodes.begin();
    auto closestDistance = DBL_MAX;
    for (const Node &n:otherNodes) {
        double aux = node.getDistanceToNode(n);
        if (aux < closestDistance) {
            closestNode = n;
            closestDistance = aux;
        }

    }
    return closestNode;
}

void NearestNeighbour::append_vector(vector<unsigned int> &v1, vector<unsigned int> &v2) {
    for (unsigned int i :v2) {
        v1.push_back(i);
    }
}

vector<unsigned int> NearestNeighbour::getVisitOrder() {
    return this->visitOrder;
}

vector<unsigned int>
NearestNeighbour::calculatePath(unsigned int startId, unsigned int finishId, const vector<u_int> &pois) {
    initDS();
    this->start = graph.getNode(startId);
    this->end = graph.getNode(finishId);
    verifyValidNodes(pois);

    visitOrderSize = static_cast<unsigned int>(2 + nodeHashTable.size());
    findBestVisitOrder(this->start, this->end);

    this->visitOrder.push_back((finishId));

    if (this->visitOrder.size() != visitOrderSize) {
        this->lastSolution.clear();
        return this->lastSolution;
    } else {
        buildSolution();
        return this->lastSolution;
    }
}

void NearestNeighbour::findBestVisitOrder(Node &start, Node &end) {
    NodeHashTable reachableNodes = dfs.performSearch(start.getId());

    if (reachableNodes.find(end) == reachableNodes.end())
        return;

    for (Node n : nodeHashTable) {
        if (reachableNodes.find(n) == reachableNodes.end())
            return;
    }

    addNodeVisitOrder(start);

    Node closestNode;
    NodeHashTable poisToVisit = nodeHashTable;

    while (!poisToVisit.empty()) {
        closestNode = getClosestNode(start, poisToVisit);

        findBestVisitOrder(closestNode, end);

        if (visitOrder.size() != visitOrderSize - 1)
            poisToVisit.erase(closestNode);
        else
            return;
    }
    if (visitOrder.size() != visitOrderSize - 1)
        removeNodeVisitOrder(start);
}

void NearestNeighbour::buildSolution() {
    Dijkstra dijkstra(graph);
    this->solutionTotalCost = 0;

    for (unsigned int i = 0; i < visitOrder.size() - 1; i++) {
        append_vector(lastSolution, dijkstra.calcOptimalPath(visitOrder.at(i), visitOrder.at(i + 1)));

        this->solutionTotalCost += dijkstra.getSolutionWeight();

        if (i != visitOrder.size() - 2)
            lastSolution.pop_back();
    }
}

double NearestNeighbour::getSolutionWeight() const {
    return this->solutionTotalCost;
}


