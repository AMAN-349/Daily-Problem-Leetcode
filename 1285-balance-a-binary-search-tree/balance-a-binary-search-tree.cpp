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

    void inorder(TreeNode* root,vector<TreeNode*>& nodes)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,nodes);
        nodes.push_back(root);
        inorder(root->right,nodes);
    }

    TreeNode* balancedBST(vector<TreeNode*>& nodes,int l,int r)
    {
        if (l>r) return NULL;
        
        int m=(l+r)/2;
        TreeNode* root=nodes[m];
        root->left=balancedBST(nodes,l,m-1);
        root->right=balancedBST(nodes,m+1,r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root,nodes);
        int n=nodes.size();
        TreeNode* ans=balancedBST(nodes,0,n-1);
        return ans;
    }
};