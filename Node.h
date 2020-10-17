//
// Created by Леонид Котов on 17.10.2020.
//

#ifndef BINARYTREE_NODE_H
#define BINARYTREE_NODE_H

// NodeStatus - это флаг, который говорит о состоянии вершины
enum NodeStatus {
    LINK_TO_RIGHT = 0, // Состояние ссылки -> когда вершнина служит ссылкой для доступа к правому брату. У такой вершины нет своего значения
    HAS_A_VALUE = 1, // Состояние значения -> полноценная вершина со своим значением
};

class Node {
private:
    Node* leftSon; // Указатель на левого СЫНА вершины
    Node* rightBrother; // Указатель на правого БРАТА вершины
    int value; // Значение вершины
    NodeStatus status; // Статус вершины
public:
    explicit Node();
    explicit Node(int);
    explicit Node(Node*, Node*, int);

    ~Node();

    // Геттер и сеттер для leftSon
    Node* getSon() const;
    void setSon(Node* left_s = nullptr);

    // Геттер и сеттер для rightBrother
    Node* getBrother() const;
    void setBrother(Node* right_b = nullptr);

    // Геттер и сеттер для value
    const int getValue() const;
    void setValue(int newValue = 0);

    // Геттер статуса
    const NodeStatus getStatus() const;
};


#endif //BINARYTREE_NODE_H
