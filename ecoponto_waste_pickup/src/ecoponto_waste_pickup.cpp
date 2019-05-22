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
	GraphViewer *gv = new GraphViewer(600, 600, true);
	gv->createWindow(600, 600);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");
	gv->addNode(1);
	gv->addNode(2);
	gv->addNode(3);
	gv->rearrange();
	// para arestas bidireccionais
	gv->addEdge(1,1,2,EdgeType::UNDIRECTED);
	// para arestas direccionais
	gv->addEdge(2,1,3, EdgeType::DIRECTED);
	gv->setVertexLabel(1, "Isto e um no");
	 */

	return 0;
}
