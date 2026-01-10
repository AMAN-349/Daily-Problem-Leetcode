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

    bool isValid(TreeNode* root,long long left,long long right)
    {
        if(!root)
        {
            return true;
        }
        if(root->val<=left || root->val>=right)
        {
            return false;
        }
        return isValid(root->left,left,root->val) && isValid(root->right,root->val,right);
    }

    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right) return true;
        return isValid(root,LONG_MIN,LONG_MAX);
    }
};