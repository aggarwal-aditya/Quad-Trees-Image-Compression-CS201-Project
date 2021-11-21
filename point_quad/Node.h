#include "coordinates.h"

#ifndef QUAD_TREES_NODE_H
#define QUAD_TREES_NODE_H
struct Node
{
    coordinates loc;
    int data;
    Node(coordinates _loc,int _data)
    {
        loc=_loc;
        data=_data;
    }
    Node()
    {
        data=0;
    }
};


#endif //QUAD_TREES_NODE_H
