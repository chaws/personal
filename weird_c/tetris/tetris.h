typedef enum
{
    // Straight line
    HL,
    VL,

    // Square
    SQ,

    // Podium
    // .#.
    // ###
    UP,
    RP,
    DP,
    LP,

    // Right L      | // Left L
    // .#.          | // .#.
    // .#.          | // .#.
    // .##          | // ##.
    URL,            ULL,
    RRL,            RLL,
    DRL,            DLL,
    LRL,            LLL,

    // Left Z       | // Right Z
    // ##.          | // .##
    // .##          | // ##.
    ULZ,            URZ,
    RLZ,            RRZ,
    DLZ,            DRZ,
    LLZ,            LRZ,
} piece;
