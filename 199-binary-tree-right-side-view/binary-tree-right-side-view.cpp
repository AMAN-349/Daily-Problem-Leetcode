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

    void find(TreeNode* root,int level,int& maxlevel,vector<int>& ans)
    {
        if(!root)
        {
            return;
        }
        if(level>maxlevel)
        {
            ans.push_back(root->val);
            maxlevel=level;
        }
        find(root->right,level+1,maxlevel,ans);
        find(root->left,level+1,maxlevel,ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxlevel=-1;
        find(root,0,maxlevel,ans);
        return ans;
    }
};