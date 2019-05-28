#ifndef ECOPONTO_WASTE_PICKUP_MAPPARSER_H
#define ECOPONTO_WASTE_PICKUP_MAPPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Graph/Graph.h"
#include "defs.h"
#include "GraphViewer/edgetype.h"
#include "GraphViewer/graphviewer.h"

Graph parseMap(std::string file_path_nodes, std::string file_path_edges, std::string file_path_tags);

void parseNodes(std::ifstream & fileEdges, Graph &graph);

void parseEdges(std::ifstream & fileEdges, Graph &graph);

void parseTags(std::ifstream & fileTags, Graph &graph);

nodeType getNodeType(std::string tag);

GraphViewer* buildGraphViewer(Graph & graph);

bool isMatosinhos(Node node);

bool isBoavista(Node node);

bool isParanhos(Node node);

vector<unsigned int> getMatosinhosWasteContainers(Graph &graph);
vector<unsigned int> getMatosinhosRecyclingContainers(Graph &graph);

vector<unsigned int> getBoavistaWasteContainers(Graph &graph);
vector<unsigned int> getBoavistaRecyclingContainers(Graph &graph);

vector<unsigned int> getParanhosWasteContainers(Graph &graph);
vector<unsigned int> getParanhosRecyclingContainers(Graph &graph);

#endif //ECOPONTO_WASTE_PICKUP_MAPPARSER_H
