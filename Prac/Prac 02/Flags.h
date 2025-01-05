#ifndef SENECA_FLAGS_H
#define SENECA_FLAGS_H

namespace seneca {
    
    enum class FormatFlags {
        LONG
    };

    enum class NodeType {
        DIR,   // Directory
        FILE   // Regular File
    };

    enum class OpFlags {
        RECURSIVE
    };
}

#endif