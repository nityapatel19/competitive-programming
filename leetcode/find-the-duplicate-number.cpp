class Solution {
public:
    /*
    Brute Force:
    Sort the array and check for duplicates.
    Time = O(n logn), Space = O(1)

    Better:
    Create new array of n elements and count frequencies in that. When you find an element going more than once, break.
    Time = O(n), Space = O(n)
    */

    // Floyd's Cycle Finding or Tortoise and Hare Algorithm
    /*
    Imagine linked list where every element at index i is pointing to nums[i].
    An element is duplicated, so 2 nodes point at the same duplicated value. Making a cycle in linked list.

    Index: 0  1  2  3  4
    Value: 1, 3, 4, 2, 2

    Linked List:
    1 -> 3 -> 2 -> 4 (Loop back to 2)
               \ /
                V

    Now apply Tortoise-Hare.
    */
    int findDuplicate(vector<int>& nums) {
        int hare = 0;
        int tortoise = 0;

        while (true)
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            if (hare == tortoise) break;
        }
        
        tortoise = 0;
        while (hare != tortoise)
        {
            hare = nums[hare];
            tortoise = nums[tortoise];
        }

        return hare;
    }
};
