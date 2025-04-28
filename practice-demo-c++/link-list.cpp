#include <bits/stdc++.h>
using namespace std;
typedef struct node Node;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

Node *createNode(int item, Node *next);
void printLinkList(Node *head);
Node *prepend(int item, Node *head);
Node *append(Node *head, int item);

struct node
{
    int data;
    Node *Next;
};

int main()
{
    Node *n1, *n2, *n3, *n4, *n5;
    n1 = createNode(0, NULL);
    n1 = append(n1, 1);
    n1 = append(n1, 2);
    n1 = append(n1, 3);
    printLinkList(n1);
    return 0;
}

Node *createNode(int item, Node *next)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        cout << "Error ! Could not createNode a New Node\n";
        exit(1);
    }
    newNode->data = item;
    newNode->Next = next;
    return newNode;
}
Node *prepend(int item, Node *head)
{
    Node *newNode = createNode(item, head);

    return newNode;
}

Node *append(Node *head, int item)
{
    Node *newNode = createNode(item, NULL);

    if (head == NULL)
    {
        return newNode;
    }

    Node *currentNode = head;

    while (currentNode->Next != NULL)
    {
        currentNode = currentNode->Next;
    }
    currentNode->Next = newNode;
    return head;
}
void printLinkList(Node *head)
{
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        printf("%d->", currentNode->data);
        currentNode = currentNode->Next;
    }
    printf("\n");
}