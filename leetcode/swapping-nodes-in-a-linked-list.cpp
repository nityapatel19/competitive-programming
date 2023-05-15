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
    // Does not swap nodes, only values.
    /* ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left = head, *right = head;
        for (int i = 1; i < k; i++)
            left = left->next;
        
        ListNode *endptr = left;
        while(endptr->next)
        {
            endptr = endptr->next;
            right = right->next;
        }
        swap(left->val, right->val);
        return head;
    } */

    // Swap nodes
    ListNode* swapNodes(ListNode* head, int k) {
        // To handle k=1 cases, create dummy start.
        ListNode dummy_start;
        dummy_start.next = head;
        ListNode *left = &dummy_start, *right = &dummy_start;

        for (int i = 1; i < k; i++)
            left = left->next;
        
        ListNode *endptr = left;
        while(endptr->next->next)
        {
            endptr = endptr->next;
            right = right->next;
        }

        // Left and Right are actually parents of k and -k nodes.
        swap(left->next, right->next); // Swap previous connection
        swap(left->next->next, right->next->next); // Swap next connection

        return dummy_start.next;
    }
};