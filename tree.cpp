
#ifndef test
#define test
#include "Tree.h"

int absolute_value_fun(int x) {
    if (x < 0)
        x = -x;
    return x;
}

Quad::Quad() {
    botLeft = coordinates(0, 0);
    topRight = coordinates(0, 0);
    n = nullptr;
    topLeftTree = nullptr;
    topRightTree = nullptr;
    botLeftTree = nullptr;
    botRightTree = nullptr;
}

Quad::Quad(coordinates botL, coordinates topR) {
    n = nullptr;
    topLeftTree = nullptr;
    topRightTree = nullptr;
    botLeftTree = nullptr;
    botRightTree = nullptr;
    botLeft = botL;
    topRight = topR;
}

void Quad::insert(Node *_node) {
    if (_node == nullptr)
        return;
    if (!inboundary(_node->loc))
        return;
    if (absolute_value_fun(botLeft.x - topRight.x) <= 1 && (absolute_value_fun(botLeft.x - topRight.y) <= 1)) {
        if (n == nullptr)
            n = _node;
        return;
    }
    if ((botLeft.x + topRight.x) / 2 >= _node->loc.x) {
        if (topLeftTree == nullptr) {
            topLeftTree = new Quad(coordinates(botLeft.x, botLeft.y),
                                   coordinates((botLeft.x + topRight.x) / 2, ((botLeft.y + topRight.y) / 2)));
            topLeftTree->insert(_node);
        } else {
            if (botLeftTree == nullptr)
                botLeftTree = new Quad(coordinates(botLeft.x, (botLeft.y + topRight.y) / 2),
                                       coordinates((botLeft.x + topRight.x) / 2, topRight.y));
            botLeftTree->insert(_node);
        }
    } else {
        if ((botLeft.y + topRight.y) / 2 >= _node->loc.y) {
            if (topRightTree == nullptr)
                topRightTree = new Quad(coordinates((botLeft.x + topRight.x) / 2, botLeft.y),
                                        coordinates(topRight.x, (botLeft.y + topRight.y) / 2));
            topRightTree->insert(_node);
        } else {
            if (botRightTree == nullptr)
                botRightTree = new Quad(
                        coordinates((botLeft.x + topRight.x) / 2, (botLeft.y + topRight.y) / 2),
                        coordinates(topRight.x, topRight.y));
            botRightTree->insert(_node);
        }
    }
}

Node *Quad::search(coordinates point) {
    if (!inboundary(point))
        return nullptr;
    if (n != nullptr)
        return n;
    if ((botLeft.x + topRight.x) / 2 >= point.x) {
        if ((botLeft.x + topRight.y) / 2 >= point.y) {
            if (topLeftTree == nullptr)
                return nullptr;
            return topLeftTree->search(point);
        } else {
            if (botLeftTree == nullptr)
                return nullptr;
            return botLeftTree->search(point);
        }
    } else {
        if ((botLeft.y + topRight.y) / 2 >= point.y) {
            if (topRightTree == nullptr)
                return nullptr;
            return topRightTree->search(point);
        } else {
            if (botRightTree == nullptr)
                return nullptr;
            return botRightTree->search(point);
        }
    }
}

bool Quad::inboundary(coordinates point) {
    return (point.x >= botLeft.x && point.x <= topRight.x && point.y >= botLeft.y && point.y <= topRight.y);
}

#endif
