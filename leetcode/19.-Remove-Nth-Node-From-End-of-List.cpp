#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *createNode(int item);
ListNode *removeNthFromEnd(ListNode *head, int n);

int main()
{
    ListNode *root, *h1, *h2, *h3, *h4;
    root = createNode(1);
    h1 = createNode(2);
    h2 = createNode(3);
    h3 = createNode(4);
    h4 = createNode(5);

    h1->next = h2;
    h2->next = h3;
    h3->next = h4;

    root->next = h1;
    removeNthFromEnd(root, 2);
    return 0;
}

ListNode *createNode(int item)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));

    if (newNode == NULL)
    {
        cout << "Error ! Could not createNode a New Node\n";
        exit(1);
    }
    newNode->val = item;
    newNode->next = NULL;
    return newNode;
}
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *slow = head;
    ListNode *forwardNode = head;

    /**
     * first move n node form head
     */
    while (n-- > 0)
        forwardNode = forwardNode->next;
    /**
     * if forward node is null return to head node
     */
    if (forwardNode == nullptr)
        return head->next;

    /**
     * now need to go last forward node
     * simultaniously go to slow node
     * and finaly slow node point to the jump over one node
     */
    while (forwardNode->next != nullptr)
    {
        slow = slow->next;
        forwardNode = forwardNode->next;
    }
    slow->next = slow->next->next;

    return head;
}