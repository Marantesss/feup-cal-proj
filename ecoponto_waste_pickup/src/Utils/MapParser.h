#ifndef ECOPONTO_WASTE_PICKUP_MAPPARSER_H
#define ECOPONTO_WASTE_PICKUP_MAPPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void parseNodes(std::ifstream & fileEdges);

void parseTags(std::ifstream & fileTags);

void parseEdges(std::ifstream & fileEdges);

void parseMap(std::string file_path_nodes, std::string file_path_edges, std::string file_path_tags);

#endif //ECOPONTO_WASTE_PICKUP_MAPPARSER_H
