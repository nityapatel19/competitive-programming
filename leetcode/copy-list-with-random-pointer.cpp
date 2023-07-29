/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Time: O(n), Space: O(n)
    /* Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        Node* curr = head;
        while (curr)
        {
            Node* newNode = new Node(curr->val);
            mp[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        while (curr)
        {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
    } */

    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* curr = head;
        while (curr)
        {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }
        curr = head;
        while (curr)
        {
            curr->next->random = curr->random ? curr->random->next:NULL;
            curr = curr->next->next;
        }
        curr = head;
        Node* newHead = head->next;
        while (curr)
        {
            Node* temp = curr->next;
            curr->next = temp->next;
            curr = curr->next;
            temp->next = curr ? curr->next:NULL;
        }
        return newHead;
    }
};
