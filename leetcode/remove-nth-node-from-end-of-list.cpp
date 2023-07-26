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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        while (n--)
        {
            curr = curr->next;
        }
        // If curr==NULL, n = size of list. nth from the end = first element.
        if (!curr) return head->next;
        
        ListNode* prev = head;
        while (curr->next)
        {
            curr = curr->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};
