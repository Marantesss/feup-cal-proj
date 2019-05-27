#ifndef ECOPONTO_WASTE_PICKUP_DEFS_H
#define ECOPONTO_WASTE_PICKUP_DEFS_H

#define MATOSINHOS_X 528028

#define PARANHOS_X 533327
#define PARANHOS_Y 4557202

#define BOAVISTA_UPPER_X 529642
#define BOAVISTA_LOWER_X 532548
#define BOAVISTA_UPPER_Y 4557222
#define BOAVISTA_LOWER_Y 4555511

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
