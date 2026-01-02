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
 
    int find(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        return root->val+find(root->left)+find(root->right);
    }

    bool checkTree(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
        {
            return true;
        }
        int lsum=find(root->left);
        int rsum=find(root->right);
        cout<<lsum<<" "<<rsum<<" ";
        return (lsum+rsum)==root->val && checkTree(root->left) && checkTree(root->right);
    }
};