//
// Created by Леонид Котов on 17.10.2020.
//

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

#include "Node.h"

class Tree {
private:
    unsigned int size;
    Node* root;

    bool find(Node*, int) const;
    void insert(Node*, int);
    void print(Node*, int) const;
public:
    explicit Tree();
    ~Tree();

    bool find(Tree*, int) const;
    void push(int);

    void print() const;
};


#endif //BINARYTREE_TREE_H
