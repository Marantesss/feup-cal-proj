#include "MapParser.h"

using namespace std;

void parseNodes(std::ifstream & fileEdges);

void parseTags();

void parseEdges();

void parseMap(std::string file_path_nodes, std::string file_path_edges, std::string file_path_tags) {
    //Graph returnGraph = Graph();

    //Add Nodes
    std::ifstream fileNodes(file_path_nodes);
    std::ifstream fileEdges(file_path_edges);
    std::ifstream fileTags(file_path_tags);

    if(!fileNodes.is_open()) {
        cout << "ERROR: opening file in" + file_path_nodes << endl;
        return;
    } else if (!fileEdges.is_open()) {
        cout << "ERROR: opening file in" + file_path_edges << endl;
        return;
    } else if (!fileTags.is_open()) {
        cout << "ERROR: opening file in" + file_path_tags << endl;
        return;
    }

    // ---- parsing nodes
    parseNodes(fileNodes);
    fileNodes.close();

    /*
    // ---- parsing edges
    parseFileB(fileB, edgeMap);
    fileEdges.close();

    // ---- parsing tags
    parseFileC(fileC, returnGraph, idMap, edgeMap);
    fileTags.close();
     */

    //return returnGraph;
}

void parseNodes(std::ifstream & fileNodes) {
    std::string currLine = "";

    u_int nodeCounter = 0;

    while(!fileNodes.eof()) {
        getline(fileNodes, currLine);

        // ---- OSM node id
        u_long nodeID = stoul(currLine.substr(1, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_first_of(",") + 1);
        // ----
        double node_lat = stod(currLine.substr(currLine.find_last_of(";") + 1));
        currLine = currLine.substr(0, currLine.find_last_of(";"));

        double node_long = stod(currLine.substr(currLine.find_last_of(";") + 1));

        std::string nodeName = "node" + std::to_string(nodeCounter);

        //graph.addNode(nodeX, nodeY, nodeName);
        cout << nodeID << " " << node_lat << " " << node_long << endl;

        nodeCounter++;
    }
}
