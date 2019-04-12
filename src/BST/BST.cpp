//
// Created by wuno on 3/30/19.
//
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "BST.h"

template <class TKEY, class TDATA>
BST<TKEY, TDATA>::BST(BST<TKEY, TDATA> const &source)  {
    if(source.root == nullptr) {
        root = nullptr;
    }
    else {
        copyTree(this->root, source.root);
    }
}

template <class TKEY, class TDATA>
BST<TKEY, TDATA>& BST<TKEY, TDATA>::operator=(BST const &rhs) {
    BST copy(rhs);
    swap(copy);
    return *this;
}

//template <class TKEY, class TDATA>
//BST<TKEY, TDATA>::BST(BST &&move) noexcept {
//    move.swap(*this);
//}

//template <class TKEY, class TDATA>
//BST<TKEY, TDATA>& BST<TKEY, TDATA>::operator=(BST<TKEY, TDATA> &&move) noexcept {
//    move.swap(*this);
//    return *this;
//}

template <class TKEY, class TDATA>
BST<TKEY, TDATA>::~BST() {
    deleteTree(root);
}

template <class TKEY, class TDATA>
void BST<TKEY, TDATA>::deleteTree(BSTNode *node) {
    if(node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

template <class TKEY, class TDATA>
struct BST<TKEY, TDATA>::BSTNode* BST<TKEY, TDATA>::minValueNode(BSTNode* node)
{
    struct BSTNode* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

template <class TKEY, class TDATA>
struct BST<TKEY, TDATA>::BSTNode* BST<TKEY, TDATA>::deleteNode(BSTNode* node, TKEY key) {
    if (node == NULL) return node;
    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    } else {
        if (node->left == NULL) {
            struct BSTNode *temp = node->right;
            delete(node);
            return temp;
        } else if (node->right == NULL) {
            struct BSTNode *temp = node->left;
            delete(node);
            return temp;
        }

        struct BSTNode *temp = minValueNode(node->right);

        node->key = temp->key;

        node->right = deleteNode(node->right, key);

    }
    return node;
}

template <class TKEY, class TDATA>
void BST<TKEY, TDATA>::deleteNode(TKEY key) {
    deleteNode(root, key);
}

// Remove this
//template <class TKEY, class TDATA>
//int BST<TKEY, TDATA>::getHeight(BSTNode *node) {
//    if(node == NULL) return 1;
//    int left = getHeight(node->left);
//    int right = getHeight(node->right);
//    return 1 + std::max(left, right);
//}

// Remove this
//template <class TKEY, class TDATA>
//void BST<TKEY, TDATA>::getHeight() {
//    getHeight(root);
//}

template <class TKEY, class TDATA>
int BST<TKEY, TDATA>::getHeight(BSTNode *node) {
    if (node == NULL) return 0;
    return node->height;
}

template <class TKEY, class TDATA>
int BST<TKEY, TDATA>::getMax(int a, int b) {
    return (a > b)? a : b;
}

// Get the balance factor of node
template <class TKEY, class TDATA>
int BST<TKEY, TDATA>::getBalance(BSTNode *node) {
    if(node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

template <class TKEY, class TDATA>
void BST<TKEY, TDATA>::copyTree(BSTNode *thisRoot, BSTNode *sourceRoot) {
    if(sourceRoot == nullptr) {
        thisRoot = nullptr;
    }
    else {
        thisRoot = new std::unique_ptr<BSTNode>;
        thisRoot->data = sourceRoot->data;
        copyTree(thisRoot->left, thisRoot->left);
        copyTree(thisRoot->right, thisRoot->right);
    }
}

//template <class TKEY, class TDATA>
//void BST<TKEY, TDATA>::insertNode(BSTNode *&root, TKEY &&theKey, TDATA &&theData) {
//    std::cout << "This is not firing! Good cause it was confusing!" << std::endl;
//    if(root == nullptr) {
//        root = new BSTNode{std::move(theKey), std::move(theData)};
//        return;
//    }
//    else if(theKey < root->data) {
//        insertNode(root->left, std::move(theKey), std::move(theData));
//    }
//    else {
//        insertNode(root->right, std::move(theKey), std::move(theData));
//    }
//}

template <class TKEY, class TDATA>
struct BST<TKEY, TDATA>::BSTNode* BST<TKEY, TDATA>::leftRotate(BSTNode *node) {
    if (node->right != NULL && node->right->left != NULL) {
        BSTNode *nr = node->right;
        BSTNode *nrl = nr->left;

        // Rotate Nodes
        nr->left = node;
        node->right = nrl;

        // Update Heights
        node->height = getMax(getHeight(node->left), getHeight(node->right)) + 1;
        nr->height = getMax(getHeight(nr->left), getHeight(nr->right)) + 1;

        return nr;
    }

    return node;
}

template <class TKEY, class TDATA>
struct BST<TKEY, TDATA>::BSTNode* BST<TKEY, TDATA>::rightRotate(BSTNode *node) {
    if (node->left != NULL && node->left->right != NULL) {
        BSTNode *nl = node->left;
        BSTNode *nlr = nl->right;

        // Rotate Nodes
        nl->right = node;
        node->left = nlr;

        // Update Heights
        node->height = getMax(getHeight(node->left), getHeight(node->right)) + 1;
        nl->height = getMax(getHeight(nl->left), getHeight(nl->right)) + 1;

        return nl;
    }

    return node;
}

template <class TKEY, class TDATA>
struct BST<TKEY, TDATA>::BSTNode* BST<TKEY, TDATA>::newNode(TKEY theKey, TDATA theData) {
    BSTNode* bstNode = new BSTNode();
    bstNode->key = theKey;
    bstNode->data = theData;
    bstNode->color = 'R';
    bstNode->height = 1;
    bstNode->parent = NULL;
    bstNode->left = NULL;
    bstNode->right = NULL;
}

template <class TKEY, class TDATA>
struct BST<TKEY, TDATA>::BSTNode* BST<TKEY, TDATA>::insertNode(BSTNode *&node, const TKEY &theKey, const TDATA &theData) {
    if(node == nullptr) {
        node = newNode(theKey, theData);
    }
    if(theKey < node->key) {
        node->left = insertNode(node->left, theKey, theData);
    }
    else if (theKey > node->key) {
        node->right = insertNode(node->right, theKey, theData);
        return node;
    } else {
        return node;
    }

    node->height = 1 + getMax(getHeight(node->left), getHeight(node->right));

    // Check what the current balance ratio of the tree is
    int balance = getBalance(node);

    // 4 cases for unbalanced tree

    // Left Left Case
    if(balance > 1 && theKey < node->left->key) return leftRotate(node);
    // Right Right Case
    if(balance < -1 && theKey > node->right->key) return leftRotate(node);
    // Left Right Case
    if(balance > 1 && theKey > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if(balance < -1 && theKey < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;

}

//template <class TKEY, class TDATA>
//void BST<TKEY, TDATA>::insert(const TKEY &theKey, const TDATA &theData) {
//    insertNode(root, theKey, theData);
//}

template <class TKEY, class TDATA>
void BST<TKEY, TDATA>::insert(TKEY &&theKey, TDATA &&theData) {
    insertNode(root, theKey, theData);
}

template <class TKEY, class TDATA>
void BST<TKEY, TDATA>::inOrderTraversal(BST<TKEY, TDATA>::BSTNode *root)  {
    // The items in the left subtree are printed first, followed
    // by the item in the root node, followed by the items in
    // the right subtree.
    if(root != nullptr) {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

template <class TKEY, class TDATA>
void BST<TKEY, TDATA>::printInOrder() {
    std::cout << " \n" << " In Order - Left, Root, Right - ";
    inOrderTraversal(root);
}

template <class TKEY, class TDATA>
void BST<TKEY, TDATA>::postOrderTraversal(BST<TKEY, TDATA>::BSTNode *root)  {
    // Print all the items in the tree to which root points.
    // The items in the left subtree are printed first, followed
    // by the items in the right subtree and then the item in the
    // root node.
    if(root != nullptr) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->data << " ";
    }
}

template <class TKEY, class TDATA>
void BST<TKEY, TDATA>::printPostOrder() {
    std::cout << " \n" << " Post Order - Left, Right, Root - ";
    postOrderTraversal(root);
}

template <class TKEY, class TDATA>
void BST<TKEY, TDATA>::preOrderTraversal(BST<TKEY, TDATA>::BSTNode *root)  {
    // Print all the items in the tree to which root points.
    // The item in the root is printed first, followed by the
    // items in the left subtree and then the items in the
    // right subtree.
    if(root != nullptr) {
        std::cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

template <class TKEY, class TDATA>
void BST<TKEY, TDATA>::printPreOrder() {
    std::cout << " \n" << " Pre Order - Root, Left, Right - ";
    preOrderTraversal(root);
}

//TODO
// Print tree in tree format