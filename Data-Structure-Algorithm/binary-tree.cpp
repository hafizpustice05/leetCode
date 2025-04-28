#include <bits/stdc++.h>
using namespace std;

typedef struct node Node;

Node *createNode(int item);
void preOrderTreeTraversing(Node *node);
void addRightNode(Node *node, Node *child);
void addLeftNode(Node *node, Node *child);

struct node
{
    int data;
    Node *Left;
    Node *Right;
};

/*
      _2_
    /    \
   7      9
  / \
 1   6
*/
int main()
{
    Node *two = createNode(2);
    Node *seven = createNode(7);
    Node *nine = createNode(9);
    addLeftNode(two, seven);
    addRightNode(two, nine);

    Node *one = createNode(1);
    Node *six = createNode(6);

    addLeftNode(seven, one);
    addRightNode(seven, six);

    preOrderTreeTraversing(two);
    return 0;
}

void preOrderTreeTraversing(Node *node)
{
    printf("%d ", node->data);

    if (node->Left != NULL)
    {
        preOrderTreeTraversing(node->Left);
    }

    if (node->Right != NULL)
    {
        preOrderTreeTraversing(node->Right);
    }
}

Node *createNode(int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        cout << "Error! Could nt create a new node";
    }
    newNode->data = item;
    newNode->Left = NULL;
    newNode->Right = NULL;
    return newNode;
}

void addLeftNode(Node *node, Node *child)
{
    node->Left = child;
}

void addRightNode(Node *node, Node *child)
{
    node->Right = child;
}