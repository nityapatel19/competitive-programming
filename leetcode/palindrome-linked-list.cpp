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
    // Time: O(n), Space: O(n)
    /* bool isPalindrome(ListNode* head) {
        vector<int> nums;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = nums.size()-1;
        while (left < right)
            if (nums[left++] != nums[right--]) return false;
        
        return true;
    } */

    // Time: O(n), Space: O(n)
    /* bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *slow = head, *fast = head;
        stack<int> nums;
        while (fast && fast->next)
        {
            nums.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) nums.push(slow->val); // In case of odd elements, add the middle one.
        while (slow)
        {
            if (slow->val != nums.top()) return false;
            nums.pop();
            slow = slow->next;
        }
        return true;
    } */

    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr, *next;
        curr = head;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Now slow is middle. If even elements, slow is first middle.

        // Reverse right half.
        slow->next = reverseList(slow->next);
        slow = slow->next;
        fast = head;
        // Now fast and slow should be equal for n/2 iterations.
        // 1234321 -> 1234123; 12344321 -> 12341234

        while (slow)
        {
            if (slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
    }
};
