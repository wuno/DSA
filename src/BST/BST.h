//
// Created by wuno on 3/30/19.
//

#ifndef DSA_BST_H
#define DSA_BST_H

template <class TKEY, class TDATA>
class BST {
private:
    struct BSTNode {
        TKEY key;
        TDATA data;
        char color;
        int height;
        BSTNode *parent;
        BSTNode *left;
        BSTNode *right;
    };
    BSTNode *root = nullptr;

    void copyTree(BSTNode *thisRoot, BSTNode *sourceRoot);
    BSTNode* minValueNode(BSTNode* node);
    BSTNode* deleteNode(BSTNode* node, TKEY key);
//    void insertNode(BSTNode *&root, TKEY &&theKey, TDATA &&theData);
    void insertNode(BSTNode *&root, const TKEY &theKey, const TDATA &theData);
    int getHeight(BSTNode *node);

public:
    BST() = default;
    BST(BST const &source);
    BST(BST &&move) noexcept;
    BST& operator=(BST &&move) noexcept;
    void deleteTree(BSTNode *node);
    void deleteNode(TKEY key);
    void getHeight();
    ~BST();
    BST& operator=(BST const &rhs);
//    void insert(const TKEY &key, const TDATA &data);
    void insert(TKEY &&theKey, TDATA &&theData);
    void inOrderTraversal(BST::BSTNode* root);
    void printInOrder();
    void postOrderTraversal(BST::BSTNode* root);
    void printPostOrder();
    void preOrderTraversal(BST::BSTNode* root);
    void printPreOrder();
};

#endif //DSA_BST_H