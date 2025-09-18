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

    TreeNode* find(TreeNode* root)
    {
        if(!root)
        {
            return nullptr;
        }
        TreeNode* temp2=root->right;
        root->right=find(root->left);
        root->left = nullptr;
        TreeNode* temp=root;
        while(temp->right)
        {
            temp=temp->right;
        }
        temp->right=find(temp2);
        return root;


    }

    void flatten(TreeNode* root) {
        root=find(root);
    }
};