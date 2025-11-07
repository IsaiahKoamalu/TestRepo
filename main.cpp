#include <iostream>
#include <bits/posix2_lim.h>
#include "node.cpp"

template<class T>
class BST;

template<class T>
class BSTNode
{
public:
    BSTNode() : left(nullptr), right(nullptr){}
    BSTNode(const T &element): element(element), left(nullptr), right(nullptr){}

    T element;
    BSTNode<T> *left, *right;
};

template<class T>
class BST
{
public:
    BST()
    {
        root = nullptr;
    }

    void preorder()
    {
        preorder(root);
    }

    void insert(const T &element);

protected:
    BSTNode<T> *root;

    void preorder(BSTNode<T> *root);

    virtual void visit(BSTNode<T> *p)
    {
        std::cout << p->element << ' ';
    }
};

template<class T>
void BST<T>::preorder(BSTNode<T> *nodePtr)
{
    if (nodePtr != nullptr)
    {
        visit(nodePtr);
        preorder(nodePtr->left);
        preorder(nodePtr->right);
    }
}

template<class T>
void BST<T>::insert(const T &element)
{
    BSTNode<T> *nodePtr = root, *prev = nullptr;
    while (nodePtr != nullptr)
    {
        prev = nodePtr;
        if (element < nodePtr->element)
        {
            nodePtr = nodePtr->left;
        }else
        {
            nodePtr = nodePtr->right;
        }
    }
    if (root == nullptr)
    {
        root = new BSTNode<T>(element);
    }else if (element < prev->element)
    {
        prev->left = new BSTNode<T>(element);
    }else
    {
        prev->right = new BSTNode<T>(element);
    }
}

int main()
{
    BST<Node> bst;

    Node node1(12);
    Node node3(16);
    Node node4(10);
    Node node2(14);

    bst.insert(node1);
    bst.insert(node2);
    bst.insert(node3);
    bst.insert(node4);

    bst.preorder();

    return 0;
}