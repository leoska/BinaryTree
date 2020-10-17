//
// Created by Леонид Котов on 17.10.2020.
//

#include "Node.h"
#include "stdexcept"

/**
 * @constructor
 * @this Node
 */
Node::Node() {
    leftSon = nullptr;
    rightBrother = nullptr;
    value = 0;
    status = LINK_TO_RIGHT;
}

/**
 * @constructor
 * @param int newValue
 * @this Node
 */
Node::Node(const int newValue) {
    leftSon = nullptr;
    rightBrother = nullptr;
    value = newValue;
    status = HAS_A_VALUE;
}

/**
 * @constructor
 * @param Node* left_s - Указатель на левого СЫНА вершины
 * @param Node* right_b - Указатель на правого БРАТА вершины
 * @param int newValue - Значение вершины
 * @this Node
 */
Node::Node(Node *left_s, Node *right_b, const int newValue) {
    leftSon = left_s;
    rightBrother = right_b;
    value = newValue;
    status = HAS_A_VALUE;
}

/**
 * @destructor
 * @this Node
 */
Node::~Node() {
    // Just destructor
}

/**
 * Получение указателя на левого СЫНА вершины
 *
 * @public
 * @this Node
 * @return Node*
 */
Node* Node::getSon() const {
    return leftSon;
}

/**
 * Установка нового указателя на левого СЫНА вершины
 *
 * @public
 * @param Node* left_s - Указатель на левого СЫНА вершины
 * @this Node
 * @return void
 */
void Node::setSon(Node* left_s) {
    leftSon = left_s;
}

/**
 * Получение указателя на правого БРАТА вершины
 *
 * @public
 * @this Node
 * @return Node*
 */
Node* Node::getBrother() const {
    return rightBrother;
}

/**
 * Установка нового указателя на правого БРАТА вершины
 *
 * @public
 * @param Node* right_b - Указатель на правого БРАТА вершины
 * @this Node
 * @return void
 */
void Node::setBrother(Node* right_b) {
    rightBrother = right_b;
}

/**
 * Получение значения вершины
 *
 * @public
 * @this Node
 * @return int
 */
const int Node::getValue() const {
    if (status == LINK_TO_RIGHT)
        throw std::runtime_error("Попытка получения значения вершины, у которой статус является ссылочным!");
    return value;
}

/**
 * Установка нового значения вершины
 *
 * @public
 * @param int newValue - Новое значение вершины
 * @this Node
 * @return void
 */
void Node::setValue(const int newValue) {
    status = HAS_A_VALUE;
    value = newValue;
}

/**
 * Получение статуса вершины
 *
 * @public
 * @this Node
 * @return NodeStatus
 */
const NodeStatus Node::getStatus() const {
    return status;
}
