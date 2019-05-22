cmake_minimum_required(VERSION 3.13)
project(ecoponto_waste_pickup)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(maps)
include_directories(src)

add_executable(ecoponto_waste_pickup
        maps/Aveiro/T02_edges_Aveiro.txt
        maps/Aveiro/T02_nodes_lat_lon_Aveiro.txt
        maps/Aveiro/T02_nodes_X_Y_Aveiro.txt
        maps/Aveiro/T02_tags_Aveiro.txt
        maps/Braga/T02_edges_Braga.txt
        maps/Braga/T02_nodes_lat_lon_Braga.txt
        maps/Braga/T02_nodes_X_Y_Braga.txt
        maps/Braga/T02_tags_Braga.txt
        maps/Coimbra/T02_edges_Coimbra.txt
        maps/Coimbra/T02_nodes_lat_lon_Coimbra.txt
        maps/Coimbra/T02_nodes_X_Y_Coimbra.txt
        maps/Coimbra/T02_tags_Coimbra.txt
        maps/Ermesinde/T02_edges_Ermesinde.txt
        maps/Ermesinde/T02_nodes_lat_lon_Ermesinde.txt
        maps/Ermesinde/T02_nodes_X_Y_Ermesinde.txt
        maps/Ermesinde/T02_tags_Ermesinde.txt
        maps/Fafe/T02_edges_Fafe.txt
        maps/Fafe/T02_nodes_lat_lon_Fafe.txt
        maps/Fafe/T02_nodes_X_Y_Fafe.txt
        maps/Fafe/T02_tags_Fafe.txt
        maps/Gondomar/T02_edges_Gondomar.txt
        maps/Gondomar/T02_nodes_lat_lon_Gondomar.txt
        maps/Gondomar/T02_nodes_X_Y_Gondomar.txt
        maps/Gondomar/T02_tags_Gondomar.txt
        maps/Lisboa/T02_edges_Lisboa.txt
        maps/Lisboa/T02_nodes_lat_lon_Lisboa.txt
        maps/Lisboa/T02_nodes_X_Y_Lisboa.txt
        maps/Lisboa/T02_tags_Lisboa.txt
        maps/Maia/T02_edges_Maia.txt
        maps/Maia/T02_nodes_lat_lon_Maia.txt
        maps/Maia/T02_nodes_X_Y_Maia.txt
        maps/Maia/T02_tags_Maia.txt
        maps/Porto/T02_edges_Porto.txt
        maps/Porto/T02_nodes_lat_lon_Porto.txt
        maps/Porto/T02_nodes_X_Y_Porto.txt
        maps/Porto/T02_tags_Porto.txt
        maps/Portugal/T02_edges_Portugal.txt
        maps/Portugal/T02_nodes_lat_lon_Portugal.txt
        maps/Portugal/T02_nodes_X_Y_Portugal.txt
        maps/Portugal/T02_tags_Portugal.txt
        maps/Viseu/T02_edges_Viseu.txt
        maps/Viseu/T02_nodes_lat_lon_Viseu.txt
        maps/Viseu/T02_nodes_X_Y_Viseu.txt
        maps/Viseu/T02_tags_Viseu.txt
        src/GraphViewer/connection.cpp
        src/GraphViewer/connection.h
        src/ecoponto_waste_pickup.cpp
        src/GraphViewer/edgetype.h
        src/GraphViewer/graphviewer.cpp
        src/GraphViewer/graphviewer.h
        src/GraphViewerController.jar
        src/Graph/edge.cpp src/Graph/edge.h
        src/Graph/Node.cpp src/Graph/Node.h
        src/Utils/MapParser.cpp src/Utils/MapParser.h
        src/Graph/Graph.cpp src/Graph/Graph.h)
