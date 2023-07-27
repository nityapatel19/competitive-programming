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
    /* ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> nodes;
        while (headA || headB)
        {
            if (headA)
            {
                if (nodes.find(headA) != nodes.end()) return headA;
                nodes.insert(headA);
                headA = headA->next;
            }
            if (headB)
            {
                if (nodes.find(headB) != nodes.end()) return headB;
                nodes.insert(headB);
                headB = headB->next;
            }
        }
        return NULL;
    } */

    // Time: O(n), Space: O(n)
    /* ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> nodes;
        while (headA)
        {
            nodes.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (nodes.find(headB) != nodes.end()) return headB;
            headB = headB->next;
        }
        return NULL;
    } */

    // Time: O(n), Space: O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0, lengthB = 0;
        ListNode *tempA=headA, *tempB=headB;
        while (tempA || tempB)
        {
            if (tempA)
            {
                lengthA++; tempA = tempA->next;
            }
            if (tempB)
            {
                lengthB++; tempB = tempB->next;
            }
        }
        int diff = lengthA - lengthB;

        tempA = headA; tempB = headB;
        if (diff < 0) while (diff--) tempB = tempB->next;
        else while (diff--) tempA = tempA->next;

        while (tempA && tempB)
        {
            if (tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return NULL;
    }
};
