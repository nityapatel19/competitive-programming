/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void sumNumbersHelper(TreeNode* root, int& sum, int& curr_num) {
        curr_num = curr_num*10 + root->val;
        if (root->left==NULL && root->right==NULL) {
            sum += curr_num;
            cout << curr_num <<' '<< sum << endl;
            return;
        }
        if (root->left) {
            sumNumbersHelper(root->left, sum, curr_num);
            curr_num = curr_num/10;
        }
        if (root->right) {
            sumNumbersHelper(root->right, sum, curr_num);
            curr_num = curr_num/10;
        }
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0, curr_num = 0;
        sumNumbersHelper(root, sum, curr_num);
        return sum;
    }
};

