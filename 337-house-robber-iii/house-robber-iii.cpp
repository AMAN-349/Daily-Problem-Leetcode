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

    pair<int,int> find(TreeNode* root)
    {
        if(!root)
        {
            return {0,0};
        }
        pair<int,int> left=find(root->left);
        pair<int,int> right=find(root->right);

        int inc=root->val+left.second+right.second;
        int exc=max(left.first,left.second)+max(right.first,right.second);

        return {inc,exc};
    }

    int rob(TreeNode* root) {
        pair<int,int> ans=find(root);
        return max(ans.first,ans.second);
    }
};