#include "Dijkstra.h"

Dijkstra::Dijkstra(const Graph &graph): graph(graph) {}

vector<unsigned int> & Dijkstra::calcOptimalPath(unsigned int startNodeId, unsigned int finishNodeId) {

    // ---- initialize start and finish nodes
    startNode = Node(startNodeId);
    finishNode = Node(finishNodeId);

    // ---- populate queue graph's nodes
    checkedDijNodes.clear();
    lastSolution.clear();
    populateQueue();

    while (!pQueue.empty()) {
        //---- Analise the node on top of the priority queue
        topDNode = *(pQueue.begin());

        // ---- Check if already reached the optimal solution
        // (finish node will be on top of the queue)
        if(foundOptimalSolution()) {
            buildPath();    //Fills 'lastSolution' with the computed solution
            break;
        }

        // ---- Check if node is a dead end, is so remove it from the queue
        if(topDNode.isDeadEnd()) {
            pQueue.erase(topDNode);
            continue;
        }

        //Analise next nodes and updateQueue
        updateQueue();

    }

    return lastSolution;
}

void Dijkstra::populateQueue() {
    pQueue.clear();

    for (unsigned int i = 0; i < this->graph.getNumNodes(); i++) {
        if (i == this->startNode.getId()) {
            this->pQueue.emplace(this->startNode,0);
        }
        else {
            this->pQueue.emplace(this->graph.getNode(i));
        }
    }
}

// Check if the current node has been analised (if it has, it will be in checkedDNodes)
bool Dijkstra::isCheckedNode(unsigned int nodeId) const {
    return (checkedDijNodes.find(nodeId) != checkedDijNodes.end());
}

void Dijkstra::updateNodeOnQueue(const DijNode & currDNode, set<DijNode> & queue) {
    // If it has not been analised and the current path offers a better way, update it on the priority queue
    for (set<DijNode>::iterator it=queue.begin() ; it!=queue.end() ; it++) {
        if (it->getId() == currDNode.getId()) {
            if (currDNode.getTotalWeight() < it->getTotalWeight()) {
                queue.erase(it);
                queue.insert(currDNode);
            }
            return;
        }
    }
}

// Takes the finish node that should be on top of the queue and creates a path from recurrent previous nodes
void Dijkstra::buildPath() {

    this->solutionTotalCost = this->topDNode.getTotalWeight();
    this->checkedDijNodes.insert(topDNode);

    lastSolution.clear();

    unsigned int currDNodeId = this->finishNode.getId();
    while (currDNodeId != UINT_MAX) {
        lastSolution.insert(lastSolution.begin(), currDNodeId);
        currDNodeId = getCheckedNode(currDNodeId).getLastNodeId();
    }
}

// Goes through queue's top node's children and updates them in the queue
void Dijkstra::updateQueue(){
    pQueue.erase(pQueue.begin());
    checkedDijNodes.insert(this->topDNode);

    for (Edge e : this->topDNode.getEdges()) {

        if (isCheckedNode(e.destNodeId)) { // Already checked this node
            continue;
        }

        //get edge's destination
        DijNode currDNode = DijNode(this->graph.getNode(e.destNodeId),
                                topDNode.getId(),
                                topDNode.getTotalWeight() + e.weight);

        updateNodeOnQueue(currDNode, pQueue);
    }
}

// Checks if the optimal solution has been found (if final node is on top of the queue)
bool Dijkstra::foundOptimalSolution() {
    return (this->topDNode.getId() == this->finishNode.getId());
}

// Retrived a node in checkedNodes by its id
DijNode Dijkstra::getCheckedNode(unsigned int id) const{
    return *(this->checkedDijNodes.find(DijNode(id)));
}

double Dijkstra::getSolutionWeight() const{
    return solutionTotalCost;
}

bool Dijkstra::foundSolution() const {
    return !(checkedDijNodes.empty() || getCheckedNode(finishNode.getId()).getTotalWeight() == DBL_MAX);
}