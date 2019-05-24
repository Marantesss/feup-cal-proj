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
    parseTags(fileTags, returnGraph);
    fileTags.close();

    return returnGraph;
}

void parseNodes(std::ifstream & fileNodes, Graph &graph) {
    std::string currLine = "";
    getline(fileNodes, currLine);

    u_int nodeCounter = 0;

    while(!fileNodes.eof()) {
        getline(fileNodes, currLine);

        // ---- OSM node id
        unsigned int nodeId = stoul(currLine.substr(1, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_first_of(",") + 2);
        // ---- Latitude coordinate
        double node_lat = stod(currLine.substr(0, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_last_of(",") + 2);
        // ---- longitude coordinate
        double node_long = stod(currLine.substr(0, currLine.find_first_of(")")));

        std::string nodeName = "node " + std::to_string(nodeCounter);

        graph.addNode(nodeId, node_lat, node_long, nodeName);

        nodeCounter++;
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

        double weight = graph.getNode(originNodeID).getDistanceToNode(graph.getNode(destNodeID));

        graph.addEdge(originNodeID, destNodeID, weight))
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

nodeType getNodeType(std::string tag) {
    if (tag == "amenity=waste_basket\r")
        return WASTE_BASKET;
    else if (tag == "amenity=recycling\r")
        return RECYCLING_CONTAINER; // TODO recycling container or recycling centre are both valid
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
        return WASTE_DISPOSAL; // TODO waste disposal or waste basket are both valid
    else
        return REGULAR;
}
