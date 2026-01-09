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

    int maxHt(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        return 1+max(maxHt(root->left),maxHt(root->right));
    }

    void findNodesAtDistanceK(TreeNode* root,int k,vector<TreeNode*>& v)
    {
        if(!root)
        {
            return;
        }
        if(k==1)
        {
            v.push_back(root);
            return;
        }
        findNodesAtDistanceK(root->left,k-1,v);
        findNodesAtDistanceK(root->right,k-1,v);
    }

    TreeNode* findAncestor(TreeNode* root,TreeNode* left,TreeNode* right)
    {
        if(!root)
        {
            return NULL;
        }
        if(root==left || root==right)
        {
            return root;
        }
        TreeNode* l=findAncestor(root->left,left,right);
        TreeNode* r=findAncestor(root->right,left,right);
        if(l!=NULL && r!=NULL)
        {
            return root;
        }
        if(l!=NULL)
        {
            return l;
        }
        return r;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int k=maxHt(root);
        vector<TreeNode*> v;
        findNodesAtDistanceK(root,k,v);
        if(v.size()==1)
        {
            return *v.begin();
        }
        cout<<v.size()<<" ";
        TreeNode* ans=v[0];
        for(int i=1;i<v.size();i++)
        {
            ans=findAncestor(root,ans,v[i]);
        }
        return ans;
    }
};