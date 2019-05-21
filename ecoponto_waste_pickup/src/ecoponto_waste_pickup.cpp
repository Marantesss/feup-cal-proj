#include <cstdio>
#include "GraphViewer/graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;

int main() {
	cout << "EcoPonto - Selective Waste Pickup!!!" << endl;
	cout << "Under Construction!!!" << endl;

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

	return 0;
}
