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

    TreeNode* find(vector<int>& pre,int& index,int lower,int higher)
    {
        if(index==pre.size() || pre[index]<lower || pre[index]>higher)
        {
            return NULL;
        }


        int val=pre[index++];
        TreeNode* root=new TreeNode(val);

        root->left=find(pre,index,lower,val);
        root->right=find(pre,index,val,higher);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        return find(preorder,ind,INT_MIN,INT_MAX);
    }
};