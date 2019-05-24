#include <cstdio>
#include "GraphViewer/graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Utils/MapParser.h"
#include "Graph/Graph.h"

using namespace std;

GraphViewer* loadMap(Graph & graph) {

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

        n.setX(n.getX() - minX);
        n.setY(n.getY() - minY);

        xPercent = (n.getX()) / graphWidth;
        yPercent = 1.0 - ((n.getY()) / graphHeight);

        gv->addNode(n.getId(), (int) (xPercent * 4000), (int) (yPercent * 2000));

        switch (n.getType()) {
            case WASTE_DISPOSAL:
                gv->setVertexColor(n.getId(), "orange");
                gv->setVertexLabel(n.getId(), "Waste Container");
                break;
                /*case WASTE_TRANSFER_STATION:
                    gv->setVertexColor(n.getId(), "orange");
                    gv->setVertexLabel(n.getId(), "Waste Transfer Station");
                    break;*/
            case LANDFILL:
                gv->setVertexColor(n.getId(), "red");
                gv->setVertexLabel(n.getId(), "Landfill");
                break;
            case RECYCLING_CONTAINER:
                gv->setVertexColor(n.getId(), "green");
                gv->setVertexLabel(n.getId(), "Recycling Container");
                break;
            case RECYCLING_CENTRE:
                gv->setVertexColor(n.getId(), "yellow");
                gv->setVertexLabel(n.getId(), "Recycling Centre");
                break;
                /*case WASTE_BASKET:
                    gv->setVertexColor(n.getId(), "black");
                    gv->setVertexLabel(n.getId(), "Waste Basket");
                    break;
                case BIN:
                    gv->setVertexColor(n.getId(), "cyan");
                    gv->setVertexLabel(n.getId(), "Bin");
                    break;*/
        }
    }


    int edgeId = 0;
    vector<Edge> edges;

    for (size_t i = 0; i < graph.getNumNodes(); i++) {
        Node n = graph.getNodeByIndex(i);
        edges = n.getEdges();
        for (Edge e : edges) {
            gv->removeEdge(edgeId);
            gv->addEdge(edgeId, n.getId(), e.destNodeId, EdgeType::DIRECTED);
            edgeId++;
        }
    }

    gv->rearrange();

    return gv;
}

int main() {
    cout << " ----- WELCOME TO ECOPONTO WASTE PICKUP ----- " << endl;
    cout << "Loading Porto Map...";
    Graph graph = Graph();
    graph = parseMap("../maps/Porto/T02_nodes_X_Y_Porto.txt", "../maps/Porto/T02_edges_Porto.txt", "../maps/Porto/T02_tags_Porto.txt");

    GraphViewer* gv = loadMap(graph);

    cout << endl << "Porto Map loaded!" << endl;

    return 0;

}
