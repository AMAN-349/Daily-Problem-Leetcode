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

    void find(TreeNode* root,string& temp,vector<string>& ans)
    {
        int len=temp.size();
        if(!root)
        {
            return;
        }
        if(!temp.empty()) temp += "->";
        temp+=to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(temp);
        }
        find(root->left,temp,ans);
        find(root->right,temp,ans);
        temp.resize(len);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp="";
        find(root,temp,ans);
        return ans;
    }
};