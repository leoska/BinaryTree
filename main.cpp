#include <iostream>
#include "Tree.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Hello, World!" << std::endl;

    Tree tr;

    tr.push(5);
    tr.push(7);
    tr.push(3);
    tr.push(6);

    tr.print();

    tr.push(88);
    tr.push(35);
    tr.push(1);



    return 0;
}
