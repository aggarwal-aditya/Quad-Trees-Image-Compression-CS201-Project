//
// Created by Aditya Aggarwal on 22-10-2021.
//
#ifndef test
#define test

int absolute_value(int x) {
    if (x < 0)
        x = -x;
    return x;
}

#include "Tree.h"

Quad::Quad() {
    topLeft = coordinates(0, 0);
    botRight = coordinates(0, 0);
    n = nullptr;
    topLeftTree = nullptr;
    topRightTree = nullptr;
    botLeftTree = nullptr;
    botRightTree = nullptr;
}

Quad::Quad(coordinates topL, coordinates botR) {
    n = nullptr;
    topLeftTree = nullptr;
    topRightTree = nullptr;
    botLeftTree = nullptr;
    botRightTree = nullptr;
    topLeft = topL;
    botRight = botR;
}

void Quad::insert(Node *_node) {
    if (_node == nullptr)
        return;
    if (!inboundary(_node->loc))
        return;
    if (absolute_value(topLeft.x - botRight.x) <= 1 && absolute_value((topLeft.x - botRight.y) <= 1)) {
        if (n == nullptr)
            n = _node;
        return;
    }
    if ((topLeft.x + botRight.x) / 2 >= _node->loc.x) {
        if (topLeftTree == nullptr) {
            topLeftTree = new Quad(coordinates(topLeft.x, topLeft.y),
                                   coordinates((topLeft.x + botRight.x) / 2, ((topLeft.y + botRight.y) / 2)));
            topLeftTree->insert(_node);
        } else {
            if (botLeftTree == nullptr)
                botLeftTree = new Quad(coordinates(topLeft.x, (topLeft.y + botRight.y) / 2),
                                       coordinates((topLeft.x + botRight.x) / 2, botRight.y));
            botLeftTree->insert(_node);
        }
    } else {
        if ((topLeft.y + botRight.y) / 2 >= _node->loc.y) {
            if (topRightTree == nullptr)
                topRightTree = new Quad(coordinates((topLeft.x + botRight.x) / 2, topLeft.y),
                                        coordinates(botRight.x, (topLeft.y + botRight.y) / 2));
            topRightTree->insert(_node);
        } else {
            if (botRightTree == nullptr)
                botRightTree = new Quad(
                        coordinates((topLeft.x + botRight.x) / 2, (topLeft.y + botRight.y) / 2),
                        coordinates(botRight.x, botRight.y));
            botRightTree->insert(_node);
        }
    }
}

Node *Quad::search(coordinates point) {
    if (!inboundary(point))
        return nullptr;
    if (n != nullptr)
        return n;
    if ((topLeft.x + botRight.x) / 2 >= point.x) {
        if ((topLeft.x + botRight.y) / 2 >= point.y) {
            if (topLeftTree == nullptr)
                return nullptr;
            return topLeftTree->search(point);
        } else {
            if (botLeftTree == nullptr)
                return nullptr;
            return botLeftTree->search(point);
        }
    } else {
        if ((topLeft.y + botRight.y) / 2 >= point.y) {
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
    return (point.x >= topLeft.x && point.x <= botRight.x && point.y >= topLeft.y && point.y <= botRight.y);
}

#endif
