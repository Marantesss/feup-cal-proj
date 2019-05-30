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
#include "Graph/Container.h"

Graph parseMap(std::string file_path_nodes, std::string file_path_edges, std::string file_path_tags);

void parseNodes(std::ifstream & fileEdges, Graph &graph);

void parseEdges(std::ifstream & fileEdges, Graph &graph);

void parseTags(std::ifstream & fileTags, Graph &graph);

void parseRandomTags(Graph &graph);

nodeType getNodeType(std::string tag);

GraphViewer* buildGraphViewer(Graph & graph);

bool isMatosinhos(Node node);

bool isBoavista(Node node);

bool isParanhos(Node node);

bool isStartingNode(Node node);

bool isFinalNode(Node node);

vector<Container> getMyMapRecyclingContainers(Graph &graph);

vector<Container> getMatosinhosWasteContainers(Graph &graph);
vector<Container> getMatosinhosRecyclingContainers(Graph &graph);

vector<Container> getBoavistaWasteContainers(Graph &graph);
vector<Container> getBoavistaRecyclingContainers(Graph &graph);

vector<Container> getParanhosWasteContainers(Graph &graph);
vector<Container> getParanhosRecyclingContainers(Graph &graph);

#endif //ECOPONTO_WASTE_PICKUP_MAPPARSER_H
