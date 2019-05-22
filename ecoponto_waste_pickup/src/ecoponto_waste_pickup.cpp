#include <cstdio>
#include "GraphViewer/graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Utils/MapParser.h"
#include "Graph/Graph.h"

using namespace std;

int main() {

    Graph graph = Graph();
    graph = parseMap("../maps/Porto/T02_nodes_lat_lon_Porto.txt", "../maps/Porto/T02_edges_Porto.txt", "../maps/Porto/T02_tags_Porto.txt");

    /*
    GraphViewer *gv = new GraphViewer(1200, 1200, true);
    gv->createWindow(1200, 1200);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    double yPercent, xPercent;

    Node n = graph.getNodeByIndex(0);

    double minX = n.getLatitude();
    double minY = n.getLongitude();
    double maxX = n.getLatitude();
    double maxY = n.getLongitude();

    for(size_t i = 1; i < graph.getNumNodes(); i++){

        n = graph.getNodeByIndex(i);

        if (n.getLatitude() > maxX) {
            maxX = n.getLatitude();
        }
        else if (n.getLatitude() < minX) {
            minX = n.getLatitude();
        }

        if (n.getLongitude() > maxY) {
            maxY = n.getLongitude();
        }
        else if (n.getLongitude() < minY) {
            minY = n.getLongitude();
        }
    }

    double graphHeight = maxY - minY;
    double graphWidth = maxX - minX;

    for(size_t i = 0; i < graph.getNumNodes(); i++) {
        Node n = graph.getNodeByIndex(i);

        yPercent = 1.0 - ((n.getLongitude() - minY)/graphHeight*0.9 + 0.05); //+5% to have margins
        xPercent = (n.getLatitude() - minX)/graphWidth*0.9 + 0.05; // *90% to be within margins

        gv->addNode(i, (int)(xPercent*1200), (int)(yPercent*1200));
    }

    int edgeId=0;
    vector<Edge> edges;

    for(size_t i = 0; i < graph.getNumNodes(); i++) {
        edges = graph.getNodeByIndex(i).getEdges();
        for (Edge e : edges) {
            gv->removeEdge(edgeId++);
            gv->addEdge(edgeId++, i, graph.getNodeIndex(e.destNodeId), EdgeType::DIRECTED);
        }
    }

    gv->rearrange();
    */


    return 0;
}
