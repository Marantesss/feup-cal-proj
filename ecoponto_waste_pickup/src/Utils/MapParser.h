#ifndef ECOPONTO_WASTE_PICKUP_MAPPARSER_H
#define ECOPONTO_WASTE_PICKUP_MAPPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Graph/Graph.h"
#include "defs.h"

Graph parseMap(std::string file_path_nodes, std::string file_path_edges, std::string file_path_tags);

void parseNodes(std::ifstream & fileEdges, Graph &graph);

void parseEdges(std::ifstream & fileEdges, Graph &graph);

void parseTags(std::ifstream & fileTags, Graph &graph);

nodeType getNodeType(std::string tag);

#endif //ECOPONTO_WASTE_PICKUP_MAPPARSER_H
