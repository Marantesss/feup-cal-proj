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
#include <algorithm>
#include <ctime>
#include "Algorithms/DFS.h"

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

vector<Container> getRecyclingContainers(unsigned int startingNode, Graph &graph);
vector<Container> getWasteContainers(unsigned int startingNode, Graph &graph);

vector<Container> getMyMapRecyclingContainers(unsigned int startingNode, Graph &graph);
vector<Container> getMyMapWasteContainers(unsigned int startingNode, Graph &graph);

vector<Container> getMatosinhosWasteContainers(unsigned int startingNode, Graph &graph);
vector<Container> getMatosinhosRecyclingContainers(unsigned int startingNode, Graph &graph);

vector<Container> getBoavistaWasteContainers(unsigned int startingNode, Graph &graph);
vector<Container> getBoavistaRecyclingContainers(unsigned int startingNode, Graph &graph);

vector<Container> getParanhosWasteContainers(unsigned int startingNode, Graph &graph);
vector<Container> getParanhosRecyclingContainers(unsigned int startingNode, Graph &graph);

#endif //ECOPONTO_WASTE_PICKUP_MAPPARSER_H
