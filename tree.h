#include "coordinates.h"
#include "coordinates.h"
#include "Node.h"
#ifndef QUAD_TREES_TREE_H
#define QUAD_TREES_TREE_H
class Quad
{
    coordinates topLeft;
    coordinates botRight;
    Node*n;
    Quad *topLeftTree;
    Quad *topRightTree;
    Quad *botLeftTree;
    Quad *botRightTree;
public:
    Quad();
    Quad(coordinates topL,coordinates botR);
    void insert(Node*);
    bool inboundary(coordinates);
    Node* search(coordinates);
};



#endif //QUAD_TREES_TREE_H
