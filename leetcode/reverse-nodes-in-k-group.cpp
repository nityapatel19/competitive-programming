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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyStart = new ListNode();
        dummyStart->next = head;
        ListNode *prev = dummyStart, *curr = head, *next = curr->next;
        int length = 0;
        while (curr)
        {
            length++;
            curr = curr->next;
        }
        int groups = length/k;
        curr = head;
        for (int i = 0; i < groups; i++)
        {
            int iters = k-1;
            while(iters--)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            curr = curr->next;
            if (next) next = next->next;
        }
        return dummyStart->next;
    }
};
