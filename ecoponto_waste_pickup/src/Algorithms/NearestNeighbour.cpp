#include "NearestNeighbour.h"

NearestNeighbour::NearestNeighbour(const Graph &graph) : graph(graph), dfs(graph) {}

void NearestNeighbour::initDS() {
    visitOrder.clear();
    lastSolution.clear();
    containerHashTable.clear();
}

void NearestNeighbour::verifyValidNodes(const vector<Container> &containers) {
    for (Container container: containers) {
        int id = container.getId();
        if (id != this->start.getId() && id != this->end.getId())
            this->containerHashTable.insert(container);
    }
}

void NearestNeighbour::addNodeVisitOrder(Node &node) {
    this->visitOrder.push_back(node.getId());
    this->containerHashTable.erase(node);
}

void NearestNeighbour::removeNodeVisitOrder(Node &node) {
    this->visitOrder.pop_back();
    this->containerHashTable.insert(node);
}

Node NearestNeighbour::getClosestNode(Node &node, const ContainerHashTable otherNodes) {
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

vector<unsigned int> NearestNeighbour::calculatePath(unsigned int startId, unsigned int finishId, const vector<Container> &containers) {
    initDS();
    this->start = graph.getNode(startId);
    this->end = graph.getNode(finishId);
    verifyValidNodes(containers);

    visitOrderSize = static_cast<unsigned int>(2 + containerHashTable.size());
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

    for (Node n : containerHashTable) {
        if (reachableNodes.find(n) == reachableNodes.end())
            return;
    }

    addNodeVisitOrder(start);

    Node closestNode;
    ContainerHashTable containersToVisit = containerHashTable;

    while (!containersToVisit.empty()) {
        closestNode = getClosestNode(start, containersToVisit);

        findBestVisitOrder(closestNode, end);

        if (visitOrder.size() != visitOrderSize - 1)
            containersToVisit.erase(closestNode);
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


