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

    void find(TreeNode* root,vector<int>& temp,vector<vector<int>>& ans,int target)
    {
        if(!root)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            temp.push_back(root->val);
            target-=root->val;
            if(target==0)
            {
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        find(root->left,temp,ans,target-root->val);
        find(root->right,temp,ans,target-root->val);
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        find(root,temp,ans,targetSum);
        return ans;
    }
};