#ifndef ECOPONTO_WASTE_PICKUP_DEFS_H
#define ECOPONTO_WASTE_PICKUP_DEFS_H

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

#endif //ECOPONTO_WASTE_PICKUP_DEFS_H
