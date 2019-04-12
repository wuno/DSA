#include <iostream>
#include "src/BST/BST.cpp"

int main()
{
    BST<int, int> tree;
    tree.insert(312, 312);
    tree.insert(123, 123);
    tree.insert(133, 133);
    tree.insert(143, 143);
    tree.insert(323, 323);
    tree.insert(543, 543);
    tree.insert(231, 231);
    tree.insert(122, 122);
    tree.insert(432, 432);
    tree.insert(4235, 4235);
    tree.insert(5422, 5422);
    tree.insert(23431, 23431);
    tree.insert(34, 34);
    tree.insert(3412, 3412);
    tree.insert(413, 413);
    tree.insert(5423, 5423);
    tree.insert(6453, 6453);
    tree.insert(234, 234);
    tree.insert(333, 333);
    tree.insert(12, 12);
    tree.printInOrder();
//    tree.printPostOrder();
//    tree.printPreOrder();
//    tree.getHeight();
    tree.deleteNode(12);
    tree.deleteNode(34);
    tree.deleteNode(122);
    tree.deleteNode(123);
    tree.deleteNode(133);
    tree.printInOrder();
    return 0;
}