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
    bool isSymmetricHelper(TreeNode *left, TreeNode *right){
        bool answer = true;
        if (left != NULL && right != NULL && left->val == right->val)
        {
            answer &= isSymmetricHelper(left->left, right->right);
            answer &= isSymmetricHelper(left->right, right->left);
        }
        else if (!(left == NULL && right == NULL))
        {
            answer = false;
        }

        return answer;
    }

    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root->left, root->right);
    }
};