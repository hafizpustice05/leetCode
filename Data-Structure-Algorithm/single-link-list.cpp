#include <bits/stdc++.h>
using namespace std;
typedef struct node Node;

Node *createNode(int item, Node *next);
Node *prepend(Node *head, int item);
Node *append(Node *head, int item);
Node *searchNode(Node *head, int item);
Node *removeNode(Node *head, Node *node);
int nodeCount(Node *head);
void printLinkList(Node *head);
void insertNode(Node *node, int item);

struct node
{
    int data;
    Node *Next;
};

int main()
{
    Node *n1, *n2, *head, *n3, *n4, *n5;

    n1 = createNode(10, NULL);
    head = n1;
    printLinkList(head);

    n2 = prepend(head, 20);
    head = n2;
    n3 = append(head, 30);
    head = n3;
    printLinkList(head);

    cout << "total node: " << nodeCount(head) << "\n";
    n5 = searchNode(head, 10);
    cout << "data: " << n5->data << " data->next:" << n5->Next << "\n";

    printLinkList(head);
    // n3 = searchNode(head, 10);
    printLinkList(n5);
    // n4 = removeNode(head, n3);
    insertNode(n5, 36);
    printLinkList(head);

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

Node *prepend(Node *head, int item)
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
        printf("%d ", currentNode->data);
        currentNode = currentNode->Next;
    }
    printf("\n");
}

int nodeCount(Node *head)
{
    int count = 1;
    Node *currentNode;
    currentNode = head;
    while (currentNode->Next != NULL)
    {
        count++;
        currentNode = currentNode->Next;
    }
    return count;
}

Node *searchNode(Node *head, int item)
{
    Node *currentNode;
    currentNode = head;

    while (currentNode->Next != NULL)
    {
        if (currentNode->data == item)
        {
            // currentNode->Next = NULL;
            return currentNode;
        }
        currentNode = currentNode->Next;
    }
    return NULL;
}

Node *removeNode(Node *head, Node *node)
{
    if (head == node)
    {
        head = node->Next;
        free(node);
        return head;
    }

    Node *currentNode = head;
    while (currentNode != NULL)
    {
        if (currentNode->Next == node)
        {
            break;
        }
        currentNode = currentNode->Next;
    }
    if (currentNode == NULL)
    {
        return head;
    }
    currentNode->Next = node->Next;
    free(node);
    return head;
}

void insertNode(Node *node, int item)
{
    Node *newNode = createNode(item, node->Next);

    node->Next = newNode;
}