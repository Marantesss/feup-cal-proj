#include "MapParser.h"

using namespace std;

void parseMap(std::string file_path_nodes, std::string file_path_edges, std::string file_path_tags) {
    //Graph returnGraph = Graph();

    // ---- git Opening files
    std::ifstream fileNodes(file_path_nodes);
    std::ifstream fileEdges(file_path_edges);
    std::ifstream fileTags(file_path_tags);

    if(!fileNodes.is_open()) {
        cout << "ERROR: opening file in " << file_path_nodes << endl;
        return;
    } else if (!fileEdges.is_open()) {
        cout << "ERROR: opening file in " << file_path_edges << endl;
        return;
    } else if (!fileTags.is_open()) {
        cout << "ERROR: opening file in " << file_path_tags << endl;
        return;
    }

    // ---- parsing nodes
    parseNodes(fileNodes);
    fileNodes.close();

    // ---- parsing edges
    parseEdges(fileEdges);
    fileEdges.close();


    // ---- parsing tags
    parseTags(fileTags);
    fileTags.close();


    //return returnGraph;
}

void parseNodes(std::ifstream & fileNodes) {
    std::string currLine = "";
    getline(fileNodes, currLine);

    u_int nodeCounter = 0;

    while(!fileNodes.eof()) {
        getline(fileNodes, currLine);

        // ---- OSM node id
        u_long nodeID = stoul(currLine.substr(1, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_first_of(",") + 2);
        // ---- Latitude coordinate
        double node_lat = stod(currLine.substr(0, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_last_of(",") + 2);
        // ---- longitude coordinate
        double node_long = stod(currLine.substr(0, currLine.find_first_of(")")));

        std::string nodeName = "node" + std::to_string(nodeCounter);

        //graph.addNode(nodeX, nodeY, nodeName);
        cout << setprecision(10) << nodeCounter << " -> " << nodeID << " " << node_lat << " " << node_long << endl;

        nodeCounter++;
    }
}

void parseEdges(std::ifstream & fileEdges) {
    std::string currLine = "";
    getline(fileEdges, currLine);

    while(!fileEdges.eof()) {
        getline(fileEdges, currLine);
        // ---- origin node
        u_long originNodeID = stoul(currLine.substr(1, currLine.find_first_of(",")));
        currLine = currLine.substr(currLine.find_first_of(",") + 2);
        // ---- destination node
        u_long destNodeID = stoul(currLine.substr(1, currLine.find_first_of(")")));

        //graph.addNode(nodeX, nodeY, nodeName);
        cout << setprecision(10) << originNodeID << " -> " << destNodeID << endl;
    }
}

void parseTags(std::ifstream & fileTags) {

    std::string currLine = "";
    getline(fileTags, currLine);

    while(!fileTags.eof()) {
        // ---- getting type
        getline(fileTags, currLine);
        std::string tag_type = currLine;
        // ---- getting number of tags of the same type
        getline(fileTags, currLine);
        int num_iter = stoi(currLine);
        cout << tag_type << endl;
        // ---- getting tags
        for(int i = 0; i < num_iter; i++) {
            getline(fileTags, currLine);
            u_long nodeID = stoi(currLine);
            cout << nodeID << endl;
        }
    }
}