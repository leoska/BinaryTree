//
// Created by Леонид Котов on 17.10.2020.
//

#include "Tree.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

/**
 * @constructor
 * @this Tree
 */
Tree::Tree() {
    root = nullptr;
    size = 0;
}

/**
 * @destructor
 * @this Tree
 */
Tree::~Tree() {

}

/**
 * Добавление нового значения в дерево
 *
 * @public
 * @param int newValue
 * @this Tree
 * @return void
 */
void Tree::push(const int newValue) {
    if (root == nullptr)
        root = new Node(newValue);
    else
        insert(root, newValue);
}

/**
 *
 * @private
 * @param Node* subroot
 * @param int newValue
 * @return Node*
 */
void Tree::insert(Node* subroot, const int newValue) {
    if (subroot == nullptr)
        return;

    int subRootValue = subroot->getValue();

    // Если элемент равен переданному значению
    if (newValue == subRootValue) {
        return;
    // Если элемент больше корня, смотрим правую ветку
    } else if (newValue > subRootValue) {
        // Если не существует левого СЫНа -> создаём вершину как ссылку для её правого брата
        if (subroot->getSon() == nullptr) {
            Node* left_s = new Node();
            subroot->setSon(left_s);
        }

        Node* son = subroot->getSon();

        if (son->getBrother() == nullptr) {
            Node* right_b = new Node(newValue);
            son->setBrother(right_b);
            return;
        }

        insert(son->getBrother(), newValue);
    // Если элемент меньше корня, смотрим левую ветку
    } else {
        if (subroot->getSon() == nullptr) {
            Node* left_s = new Node(newValue);
            subroot->setSon(left_s);
        } else if (subroot->getSon()->getStatus() == LINK_TO_RIGHT) {
            subroot->getSon()->setValue(newValue);
        } else {
            insert(subroot->getSon(), newValue);
        }
    }
}


/**
 * Вывод дерева в консоль
 *
 * @public
 * @this Tree
 * @return void
 */
void Tree::print() const {
    print(root, 4);
}

/**
 * Вывод строки дерева в консоль
 *
 * @private
 * @param Node* subroot
 * @param int width
 * @this Tree
 * @return void
 */
void Tree::print(Node* subroot, const int width) const {
    string value = subroot->getStatus() == LINK_TO_RIGHT ? " " : to_string(subroot->getValue());

    if (subroot->getBrother() != nullptr)
        cout << " \\\n" << setw(2 * width) << value << "   " << subroot->getBrother()->getValue() << endl;
    else
        cout << endl << setw(2 * width) << value << endl;

    if (subroot->getSon() != nullptr)
    {
        cout << setw(2 * width - 1) << "/";
        print(subroot->getSon(), width - 1);
    }
}

/**
 * Поиск переданного значения со значениями дочерей указанной вершины
 *
 * @private
 * @param {Node*} subroot
 * @param {int} value_s
 * @this Tree
 * @returns {bool}
 */
bool Tree::find(Node* subroot, const int value_s) const {
    if (subroot == nullptr)
        return false;

    int subRootValue = subroot->getValue();

    // Если элемент равен переданному значению
    if (value_s == subRootValue) {
        return true;
    // Если элемент больше корня, смотрим правую ветку
    } else if (value_s > subRootValue) {
        if (subroot->getSon() != nullptr)
            return find(subroot->getSon()->getBrother(), value_s);
    // Если элемент меньше корня, смотрим левую ветку
    } else {
        return find(subroot->getSon(), value_s);
    }

    return false;
}


/**
 * Поиск переданного значения со значениями вершин указанного дерева
 *
 * @public
 * @param {Tree*} subtree
 * @param {int} value_s
 * @this Tree
 * @returns {bool}
 */
bool Tree::find(Tree* subtree, const int value_s) const {
    Node* subroot = subtree->root;

    return find(subroot, value_s);
}
