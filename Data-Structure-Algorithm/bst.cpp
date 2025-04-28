#include <bits/stdc++.h>
using namespace std;
typedef struct node Node;

void addLeftChild(Node *node, Node *child);
void addRightChild(Node *node, Node *child);
void printInOrder(Node *node);
Node *bstInsert(Node *root, Node *node);
Node *bstSearch(Node *root, int item);
Node *createNode(int item);
Node *createBST();

Node *bstTransPlant(Node *root, Node *currentNode, Node *newNode);
Node *bstMinimum(Node *root);
Node *bstDelete(Node *root, Node *node);

struct node
{
    int data;
    Node *Parent;
    Node *Left;
    Node *Right;
};

int main()
{
    Node *root;
    root = createBST();
    cout << " hello: BST\n";
    printInOrder(root);

    cout << "\n";
    Node *node;
    node = bstSearch(root, 1);
    if (node != NULL)
    {
        cout << "\nWill Delete Node: " << node->data << " & Parent Node: " << node->Parent->data << "\n";
        root = bstDelete(root, node);
        cout << "BST: ";
        printInOrder(root);
        cout << "\n";
    }
    else
    {
        cout << "Node not found";
    }

    node = bstSearch(root, 3);
    if (node != NULL)
    {
        cout << "\nWill Delete: " << node->data << " " << node->Parent << "\n";
        root = bstDelete(root, node);
        cout << "BST: ";
        printInOrder(root);
        cout << "\n";
    }
    else
    {
        cout << "Node not found";
    }

    node = bstSearch(root, 17);
    if (node != NULL)
    {
        cout << "\nWill Delete: " << node->data << " " << node->Parent << "\n";
        root = bstDelete(root, node);
        cout << "BST: ";
        printInOrder(root);
        cout << "\n";
    }
    else
    {
        cout << "Node not found";
    }
    return 0;
}

Node *createNode(int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        cout << "Error! can't create a new node";
    }

    newNode->data = item;
    newNode->Parent = NULL;
    newNode->Left = NULL;
    newNode->Right = NULL;
    return newNode;
}

void addLeftChild(Node *node, Node *child)
{
    node->Left = child;
    if (child != NULL)
    {
        child->Parent = node;
    }
}

void addRightChild(Node *node, Node *child)
{
    node->Right = child;

    if (child != NULL)
    {
        child->Parent = node;
    }
}

Node *bstInsert(Node *root, Node *node)
{
    Node *parentNode, *currentNode;
    if (root == NULL)
    {
        root = node;
        return root;
    }

    parentNode = NULL;
    currentNode = root;
    while (currentNode != NULL)
    {
        parentNode = currentNode;
        if (node->data < currentNode->data)
        {
            currentNode = currentNode->Left;
        }
        else
        {
            currentNode = currentNode->Right;
        }
    }

    if (node->data < parentNode->data)
    {
        addLeftChild(parentNode, node);
    }
    else
    {
        addRightChild(parentNode, node);
    }
    return root;
}

/**
 *                 10
 *               /    \
 *             5       17
 *            / \     /  \
 *          3   7   12   19
 *         / \        \  /  \
 *        1   4       13 18 20
 */

Node *createBST()
{
    Node *root, *node;
    int i;
    root = createNode(10);
    int arr[] = {5, 17, 3, 7, 12, 19, 1, 4, 13, 18, 20, 21};
    for (i = 0; i < 12; i++)
    {
        node = createNode(arr[i]);
        root = bstInsert(root, node);
    }
    cout << "\n END OF CREATE BST\n";
    // printInOrder(root);
    return root;
}

void printInOrder(Node *node)
{
    if (node->Left != NULL)
    {
        printInOrder(node->Left);
    }
    cout << node->data << " ";
    if (node->Right != NULL)
    {
        printInOrder(node->Right);
    }
}

Node *bstSearch(Node *root, int item)
{
    Node *currentNode;
    currentNode = root;
    while (currentNode != NULL)
    {
        if (currentNode->data == item)
        {
            return currentNode;
        }
        if (item < currentNode->data)
        {
            currentNode = currentNode->Left;
        }
        else
        {
            currentNode = currentNode->Right;
        }
    }
    return currentNode;
}

Node *bstTransPlant(Node *root, Node *currentNode, Node *newNode)
{
    if (currentNode == root)
    {
        root = newNode;
        return root;
    }
    else if (currentNode == currentNode->Parent->Left)
    {
        addLeftChild(currentNode->Parent, newNode);
    }
    else
    {
        addRightChild(currentNode->Parent, newNode);
    }
    return root;
}

Node *bstMinimum(Node *root)
{
    Node *node = root;

    while (node->Left != NULL)
    {
        node = node->Left;
    }
    return node;
}

Node *bstDelete(Node *root, Node *node)
{
    Node *smallestNode;

    if (node->Left == NULL)
    {
        /**
         * There are no node in the left child
         * So node will be the changed with right child
         */
        root = bstTransPlant(root, node, node->Right);
    }
    else if (node->Right == NULL)
    {
        /**
         * There are no node in the right child
         * So node will be changed with left node
         */
        root = bstTransPlant(root, node, node->Left);
    }
    else
    {
        /**
         * There has a two node in left & right node
         * So find lowest node in the right subTree
         */
        smallestNode = bstMinimum(node->Right);

        /**
         * isnt smallestNode directly child in root node
         */
        if (smallestNode->Parent != node)
        {
            /**
             * smallestNode will be changed with the right node of smallest node
             */
            root = bstTransPlant(root, smallestNode, smallestNode->Right);
            /**
             * Smallest node will be parent of node's right subtree
             */
            addRightChild(smallestNode, node->Right);
        }
        /**
         * Node will be changed with smallest node
         */
        root = bstTransPlant(root, node, smallestNode);

        /**
         * SmallestNode will be the parent of the Node's left
         */
        addLeftChild(smallestNode, node->Left);
    }
    free(node);
    return root;
}