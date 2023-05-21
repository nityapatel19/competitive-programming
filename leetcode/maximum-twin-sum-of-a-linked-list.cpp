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
    /* int pairSum(ListNode* head) {
        ListNode* temp = head;
        stack<int> nums;
        while (temp)
        {
            nums.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        int max_twin_sum = INT_MIN;
        while (temp)
        {
            max_twin_sum = max(max_twin_sum, temp->val + nums.top());
            nums.pop(); temp = temp->next;
        }
        return max_twin_sum;
    } */
    int pairSum(ListNode* head) {
        ListNode *tempHead = nullptr, *tempCurr = head, *fast = head;
        while (fast)
        {
            fast = fast->next->next;

            ListNode *nextCurr = tempCurr->next;
            tempCurr->next = tempHead;
            tempHead = tempCurr;
            tempCurr = nextCurr;
        }
        
        int max_twin_sum = INT_MIN;
        while(tempHead)
        {
            max_twin_sum = max(max_twin_sum, tempHead->val + tempCurr->val);
            tempHead = tempHead->next;
            tempCurr = tempCurr->next;
        }
        return max_twin_sum;
    }
};
