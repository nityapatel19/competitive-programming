/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /* ListNode* swapPairs(ListNode* head) {
        // Create a dummy start
        ListNode base;
        base.next = head;
        ListNode* temp = &base;

        // temp will be the node we're at,
        // and we will swap the 2 nodes after temp.
        while (temp->next && temp->next->next)
        {
            ListNode* temp2 = temp->next;
            temp->next = temp2->next;
            temp2->next = temp->next->next;
            temp->next->next = temp2;

            temp = temp->next->next;
        }

        return base.next;
    } */

    // Simpler Solution
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;

        return temp;
    }
};
