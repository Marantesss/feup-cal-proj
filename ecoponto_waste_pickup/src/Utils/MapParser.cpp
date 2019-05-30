#include "MapParser.h"

using namespace std;

Graph parseMap(std::string file_path_nodes, std::string file_path_edges, std::string file_path_tags) {
    Graph returnGraph = Graph();

    // ---- git Opening files
    std::ifstream fileNodes(file_path_nodes);
    std::ifstream fileEdges(file_path_edges);
    std::ifstream fileTags(file_path_tags);

    if(!fileNodes.is_open()) {
        cout << "ERROR: opening file in " << file_path_nodes << endl;
        exit(EXIT_FAILURE);
    } else if (!fileEdges.is_open()) {
        cout << "ERROR: opening file in " << file_path_edges << endl;
        exit(EXIT_FAILURE);
    } else if (!fileTags.is_open()) {
        cout << "ERROR: opening file in " << file_path_tags << endl;
        exit(EXIT_FAILURE);
    }

    // ---- parsing nodes
    parseNodes(fileNodes, returnGraph);
    fileNodes.close();

    // ---- parsing edges
    parseEdges(fileEdges, returnGraph);
    fileEdges.close();

    // ---- parsing tags
    if (file_path_tags == MYMAP_TAGS_MAP)
        parseRandomTags(returnGraph);
    else
        parseTags(fileTags, returnGraph);
    fileTags.close();

    return returnGraph;
}

void parseNodes(std::ifstream & fileNodes, Graph &graph) {
    std::string currLine = "";
    getline(fileNodes, currLine);

    while(!fileNodes.eof()) {
        getline(fileNodes, currLine);

        // ---- OSM node id
        unsigned int nodeId = stoul(currLine.substr(1, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_first_of(",") + 2);
        // ---- Latitude coordinate
        double node_x = stod(currLine.substr(0, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_last_of(",") + 2);
        // ---- longitude coordinate
        double node_y = stod(currLine.substr(0, currLine.find_first_of(")")));

        graph.addNode(nodeId, node_x, node_y);
    }
}

void parseEdges(std::ifstream & fileEdges, Graph &graph) {
    std::string currLine = "";
    getline(fileEdges, currLine);

    while(!fileEdges.eof()) {
        getline(fileEdges, currLine);
        // ---- origin node
        unsigned int originNodeID = stoul(currLine.substr(1, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_first_of(",") + 1);
        // ---- destination node
        unsigned int destNodeID = stoul(currLine.substr(1, currLine.find_first_of(")")));

        // ---- bidirectional
        graph.addEdge(originNodeID, destNodeID);
        graph.addEdge(destNodeID, originNodeID);
    }
}

void parseTags(std::ifstream & fileTags, Graph &graph) {

    std::string currLine = "";
    getline(fileTags, currLine);

    while(!fileTags.eof()) {
        // ---- getting type
        getline(fileTags, currLine);
        std::string tag = currLine;
        nodeType type = getNodeType(currLine);
        // ---- getting number of tags of the same type
        getline(fileTags, currLine);
        int num_iter = stoi(currLine);
        // ---- getting tags
        for(int i = 0; i < num_iter; i++) {
            getline(fileTags, currLine);
            unsigned int nodeID = stoi(currLine);
            graph.getNode(nodeID).setType(type);
        }
    }
}

void parseRandomTags(Graph &graph) {

    // ---- generate random non repeating nodes
    srand(time(0));

    vector<unsigned int> randomNodeIDs;

    for(int i = 2; i < 900; i++) {
        randomNodeIDs.push_back(i);
    }

    random_shuffle(randomNodeIDs.begin(), randomNodeIDs.end());


    for (int i = 0; i < 30; i++) {
        graph.getNode(randomNodeIDs.at(i)).setType(RECYCLING_CONTAINER);
    }

    for (int i = 30; i < 60; i++) {
        graph.getNode(randomNodeIDs.at(i)).setType(WASTE_DISPOSAL);
    }
}

nodeType getNodeType(std::string tag) {
    if (tag == "amenity=waste_basket\r")
        return WASTE_BASKET;
    else if (tag == "amenity=recycling\r")
        return RECYCLING_CONTAINER;
    else if (tag == "amenity=waste_disposal\r")
        return WASTE_DISPOSAL;
    else if (tag == "bin=*\r")
        return BIN;
    else if (tag == "landuse=landfill\r")
        return LANDFILL;
    else if (tag == "recycling_type=container\r")
        return RECYCLING_CONTAINER;
    else if (tag == "recycling_type=centre\r")
        return RECYCLING_CENTRE;
    else if (tag == "amenity=waste_transfer_station\r")
        return WASTE_TRANSFER_STATION;
    else if (tag == "waste=*\r")
        return WASTE_DISPOSAL;
    else
        return REGULAR;
}

GraphViewer* buildGraphViewer(Graph & graph) {

    GraphViewer *gv = new GraphViewer(900, 900, false);
    gv->createWindow(900, 900);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    double yPercent, xPercent;

    Node n = graph.getNodeByIndex(0);

    double minX = n.getX();
    double minY = n.getY();
    double maxX = n.getX();
    double maxY = n.getY();

    for (size_t i = 1; i < graph.getNumNodes(); i++) {

        n = graph.getNodeByIndex(i);

        if (n.getX() > maxX) {
            maxX = n.getX();
        } else if (n.getX() < minX) {
            minX = n.getX();
        }

        if (n.getY() > maxY) {
            maxY = n.getY();
        } else if (n.getY() < minY) {
            minY = n.getY();
        }
    }


    double graphHeight = maxY - minY;
    double graphWidth = maxX - minX;

    for (size_t i = 0; i < graph.getNumNodes(); i++) {
        Node n = graph.getNodeByIndex(i);

        xPercent = (n.getX() - minX) / graphWidth;
        yPercent = 1.0 - ((n.getY() - minY) / graphHeight);

        gv->addNode(n.getId(), (int) (xPercent * 4000), (int) (yPercent * 2000));

        switch (n.getType()) {
            case WASTE_DISPOSAL:
                gv->setVertexColor(n.getId(), "orange");
                break;
            case RECYCLING_CONTAINER:
                gv->setVertexColor(n.getId(), "green");
                break;
        }

        // ---- drawing starting and ending points
        if (isStartingNode(n))
            gv->setVertexColor(n.getId(), "cyan");
        if (isFinalNode(n))
            gv->setVertexColor(n.getId(), "red");
    }


    vector<Edge> edges;

    for (size_t i = 0; i < graph.getNumNodes(); i++) {
        Node n = graph.getNodeByIndex(i);
        edges = n.getEdges();
        for (Edge e : edges) {
            gv->removeEdge(e.edgeId);
            gv->addEdge(e.edgeId, n.getId(), e.destNodeId, EdgeType::DIRECTED);
        }
    }

    gv->rearrange();

    return gv;
}

void append_vector(vector<unsigned int> &v1, vector<unsigned int> &v2) {
    for (unsigned int i :v2) {
        v1.push_back(i);
    }
}

void append_containers(vector<Container> &v1, vector<Container> &v2) {
    for (Container i :v2) {
        v1.push_back(i);
    }
}

bool isMatosinhos(Node node) {


    if (node.getX() > MATOSINHOS_X)
        return false;

    return true;
}

bool isBoavista(Node node) {

    if (node.getX() < BOAVISTA_UPPER_X)
        return false;
    if(node.getY() > BOAVISTA_UPPER_Y)
        return false;
    if(node.getX() > BOAVISTA_LOWER_X)
        return false;
    if(node.getY() < BOAVISTA_LOWER_Y)
        return false;

    return true;

}

bool isParanhos(Node node) {

    if (node.getX() < PARANHOS_X)
        return false;
    if (node.getY() < PARANHOS_Y)
        return false;

    return true;
}

bool isStartingNode(Node node) {
    unsigned int id = node.getId();

    return id == MATOSINHOS_PARKING_NODE_ID || id == BOAVISTA_PARKING_NODE_ID || id == PARANHOS_PARKING_NODE_ID || id == MYMAP_PARKING_NODE_ID;
}

bool isFinalNode(Node node) {
    unsigned int id = node.getId();

    return id == MATOSINHOS_WASTE_STATION_NODE_ID || id == BOAVISTA_WASTE_STATION_NODE_ID || id == PARANHOS_WASTE_STATION_NODE_ID || id == MYMAP_WASTE_STATION_NODE_ID;
}

void getContainers(unsigned int startingNode, Graph &graph, vector<Container> &wasteContainers, vector<Container> &recyclingContainers) {

    if (startingNode == MATOSINHOS_PARKING_NODE_ID)
        getMatosinhosContainers(graph, wasteContainers, recyclingContainers);
    else if (startingNode == BOAVISTA_PARKING_NODE_ID)
        getBoavistaContainers(graph, wasteContainers, recyclingContainers);
    else if (startingNode == PARANHOS_PARKING_NODE_ID)
        getParanhosContainers(graph, wasteContainers, recyclingContainers);
    else if (startingNode == MYMAP_PARKING_NODE_ID)
        getMyMapContainers(graph, wasteContainers, recyclingContainers);
}

void getMyMapContainers(Graph &graph, vector<Container> &wasteContainers, vector<Container> &recyclingContainers) {
    DFS dfs = DFS(graph);
    NodeHashTable accessNodes = dfs.performSearch(MYMAP_PARKING_NODE_ID);
    vector<Container>::iterator iter;

    for (Node n : accessNodes) {
        if (n.getType() == WASTE_DISPOSAL) {
            Container newContainer = Container(n);
            if (newContainer.isValidPickup())
                wasteContainers.push_back(newContainer);
        }
        else if (n.getType() == RECYCLING_CONTAINER) {
            Container newContainer = Container(n);
            if (newContainer.isValidPickup())
                recyclingContainers.push_back(newContainer);
        }
    }
}

void getMatosinhosContainers(Graph &graph, vector<Container> &wasteContainers, vector<Container> &recyclingContainers) {
    DFS dfs = DFS(graph);
    NodeHashTable accessNodes = dfs.performSearch(MATOSINHOS_PARKING_NODE_ID);
    vector<Container>::iterator iter;

    for (Node n : accessNodes) {
        if (n.getType() == WASTE_DISPOSAL && isMatosinhos(n)) {
            Container newContainer = Container(n);
            if (newContainer.isValidPickup())
                wasteContainers.push_back(newContainer);
        }
        else if (n.getType() == RECYCLING_CONTAINER && isMatosinhos(n)) {
            Container newContainer = Container(n);
            if (newContainer.isValidPickup())
                recyclingContainers.push_back(newContainer);
        }
    }
}

void getBoavistaContainers(Graph &graph, vector<Container> &wasteContainers, vector<Container> &recyclingContainers) {

    DFS dfs = DFS(graph);
    NodeHashTable accessNodes = dfs.performSearch(BOAVISTA_PARKING_NODE_ID);
    vector<Container>::iterator iter;

    for (Node n : accessNodes) {
        if (n.getType() == WASTE_DISPOSAL && isBoavista(n)) {
            Container newContainer = Container(n);
            if (newContainer.isValidPickup())
                wasteContainers.push_back(newContainer);
        }
        else if (n.getType() == RECYCLING_CONTAINER && isBoavista(n)) {
            Container newContainer = Container(n);
            if (newContainer.isValidPickup())
                recyclingContainers.push_back(newContainer);
        }
    }
}



void getParanhosContainers(Graph &graph, vector<Container> &wasteContainers, vector<Container> &recyclingContainers) {
    DFS dfs = DFS(graph);
    NodeHashTable accessNodes = dfs.performSearch(PARANHOS_PARKING_NODE_ID);
    vector<Container>::iterator iter;

    for (Node n : accessNodes) {
        if (n.getType() == WASTE_DISPOSAL && isParanhos(n)) {
            Container newContainer = Container(n);
            if (newContainer.isValidPickup())
                wasteContainers.push_back(newContainer);
        }
        else if (n.getType() == RECYCLING_CONTAINER && isParanhos(n)) {
            Container newContainer = Container(n);
            if (newContainer.isValidPickup())
                recyclingContainers.push_back(newContainer);
        }
    }
}
