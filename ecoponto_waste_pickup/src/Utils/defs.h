#ifndef ECOPONTO_WASTE_PICKUP_DEFS_H
#define ECOPONTO_WASTE_PICKUP_DEFS_H

#define PORTO_NODE_MAP "../maps/Porto/T02_nodes_X_Y_Porto.txt"
#define PORTO_EDGE_MAP "../maps/Porto/T02_edges_Porto.txt"
#define PORTO_TAGS_MAP "../maps/Porto/T02_tags_Porto.txt"

#define MYMAP_NODE_MAP "../maps/MyMap/MyMapNodes.txt"
#define MYMAP_EDGE_MAP "../maps/MyMap/MyMapEdges.txt"
#define MYMAP_TAGS_MAP "../maps/MyMap/MyMapTags.txt"

#define MATOSINHOS_X 528028

#define PARANHOS_X 533327
#define PARANHOS_Y 4557202

#define BOAVISTA_UPPER_X 529642
#define BOAVISTA_LOWER_X 532548
#define BOAVISTA_UPPER_Y 4557222
#define BOAVISTA_LOWER_Y 4555511

#define MATOSINHOS_PARKING_NODE_ID 311887304
#define MATOSINHOS_WASTE_STATION_NODE_ID 1108123556

#define PARANHOS_PARKING_NODE_ID 432578849
#define PARANHOS_WASTE_STATION_NODE_ID 1223751626

#define BOAVISTA_PARKING_NODE_ID 428214906
#define BOAVISTA_WASTE_STATION_NODE_ID 428214905

#define MYMAP_PARKING_NODE_ID 1
#define MYMAP_WASTE_STATION_NODE_ID 900

#define TRUCK_MAX_CAPACITY 1000
#define CONTAINER_MAX_CAPACITY 100
#define CONTAINER_PICKUP_VALID 0.4

enum nodeType {
    REGULAR,                 // regular node
    WASTE_DISPOSAL,          // medium size disposal bin, for bagged up household items
    WASTE_TRANSFER_STATION,  // accepts or transfers waste in bulk
    LANDFILL,                // accepts regular waste for burial
    RECYCLING_CONTAINER,     // medium size disposal bins, that accepts waste for recycling
    RECYCLING_CENTRE,        // recycling centre
    WASTE_BASKET,            // small size disposal bin
    BIN                      // presence of a waste basket at/in a facility
};

enum truckType {
    WASTE,
    RECYCLE
};

#endif //ECOPONTO_WASTE_PICKUP_DEFS_H
