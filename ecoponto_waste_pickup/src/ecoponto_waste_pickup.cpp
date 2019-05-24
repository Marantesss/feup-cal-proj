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
    graph = parseMap("../maps/Porto/T02_nodes_X_Y_Porto.txt", "../maps/Porto/T02_edges_Porto.txt", "../maps/Porto/T02_tags_Porto.txt");


    GraphViewer *gv = new GraphViewer(900, 900, false);
    gv->createWindow(900, 900);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    double yPercent, xPercent;

    Node n = graph.getNodeByIndex(0);

    double minX = n.getLatitude();
    double minY = n.getLongitude();
    double maxX = n.getLatitude();
    double maxY = n.getLongitude();

    for (size_t i = 1; i < graph.getNumNodes(); i++) {

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

        n.setLatitude(n.getLatitude() - minX);
        n.setLongitude(n.getLongitude() - minY);

        yPercent = 1.0 - ((n.getLongitude())/graphHeight*0.9 + 0.05); //+5% to have margins
        xPercent = (n.getLatitude())/graphWidth*0.9 + 0.05; // *90% to be within margins

        gv->addNode(i, (int)(xPercent*4000), (int)(yPercent*2000));

        if (i == 9830) cout << n.getId() << endl;
    }


    int edgeId=0;
    vector<Edge> edges;

    for(size_t i = 0; i < graph.getNumNodes(); i++) {
        edges = graph.getNodeByIndex(i).getEdges();
        for (Edge e : edges) {
            gv->removeEdge(edgeId);
            gv->addEdge(edgeId, i, e.destNodeId, EdgeType::DIRECTED);
            edgeId++;
        }
    }

    gv->rearrange();

    return 0;
}
