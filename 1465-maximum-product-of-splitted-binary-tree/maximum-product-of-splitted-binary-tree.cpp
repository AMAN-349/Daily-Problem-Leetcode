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
    long long t;
    long long ans=0;
    long long sum=0;
    long long findsum(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        return root->val+findsum(root->left)+findsum(root->right);
    }

    long long find(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        long long leftsum=find(root->left);
        long long rightsum=find(root->right);
        long long curr=leftsum+rightsum+root->val;
        ans=max(ans,(curr*(abs(t-curr))));
        return curr;
    }

    int maxProduct(TreeNode* root) {
        long long mod=1e9+7;
        long long totalsum=findsum(root);
        t=totalsum;
        long long temp=find(root);
        return ans%mod;
    }
};