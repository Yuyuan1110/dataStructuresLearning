#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {};
};

class BinaryTree
{
private:
    Node *insertRec(Node *node, int value)
    {
        if (node == nullptr)
        {
            return node;
        }
        if (value < node->data)
        {
            node->left = insertRec(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertRec(node->right, value);
        }
        return node;
    };
    Node *deleteRec(Node *node, int value)
    {
        if (node == nullptr)
        {
            return node;
        }
        if (value < node->data)
        {
            node->left = deleteRec(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteRec(node->right, value);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    };
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

public:
    Node *root;

    BinaryTree() : root(nullptr) {};
    void insert(int value);
    void deleteNode(int value);
    void inorderTraversal();
};

void BinaryTree::insert(int value)
{
}

void BinaryTree::deleteNode(int value)
{
}

void BinaryTree::inorderTraversal() {

};