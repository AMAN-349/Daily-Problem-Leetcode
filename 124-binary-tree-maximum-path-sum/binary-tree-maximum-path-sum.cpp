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
    int res=INT_MIN;
    int findmax(int value,int left,int right)
    {
        res=max(res,value+left+right);
        int temp=(value+max(left,right));
        return temp;
    }

    int find(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int val=root->val;
        int left=max(0,find(root->left));
        int right=max(0,find(root->right));
        return findmax(val,left,right);

    }
 
    int maxPathSum(TreeNode* root) {
        int ans=find(root);
        return res;
    }
};