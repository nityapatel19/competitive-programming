/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Time: O(n), Space: O(n)
    /* bool hasCycle(ListNode *head) {
        set<ListNode*> nodes;
        
        while (head)
        {
            if (nodes.find(head) != nodes.end()) return true;
            nodes.insert(head);
            head = head->next;
        }
        return false;
    } */

    // Time: O(n), Space: O(1)
    bool hasCycle(ListNode *head) {
        ListNode *tortoise = head, *hare = head;

        while (tortoise && hare && hare->next)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) return true;
        }
        return false;
    }
};
