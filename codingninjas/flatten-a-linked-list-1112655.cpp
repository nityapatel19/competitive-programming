/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* merge(Node* l1, Node* l2)
{
    // Some issue with setting NULLs.
    /* Node* temp = new Node();
    Node* res = temp;
    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            temp->child = l1;
            temp = temp->child;
            l1 = l1->child;
        }
        else
        {
            temp->child = l2;
            temp = temp->child;
            l2 = l2->child;
        }
    }
    if (l1) temp->child = l1;
    if (l2) temp->child = l2;
    return res->child; */

    if (!l1)
	{
		l2->next = NULL;
		return l2;
	}
    if (!l2)
    {
        l1->next = NULL;
        return l1;
    }
    Node* merged;
    if (l1->data < l2->data)
    {
        merged = l1;
        merged->child = merge(l1->child, l2);
    }
    else
    {
        merged = l2;
        merged->child = merge(l1, l2->child);
    }
    merged->next = nullptr;
    return merged;
}
Node* flattenLinkedList(Node* head) 
{
    if (head==NULL || head->next == NULL) return head;
    head->next = flattenLinkedList(head->next);
    head = merge(head, head->next);
    return head;
}
