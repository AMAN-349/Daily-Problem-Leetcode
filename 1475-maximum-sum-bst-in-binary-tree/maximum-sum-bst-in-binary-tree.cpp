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

struct NodeValue{
    int maxNode,minNode,maxSize,sum;
    NodeValue(int maxi,int mini,int s)
    {
        maxNode=maxi;
        minNode=mini;
        sum=s;
    }
};

class Solution {
public:
    int maxSum=0;
    NodeValue* largestBST(TreeNode* root)
    {
        if(!root)
        {
            return new NodeValue(INT_MIN,INT_MAX,0);
        }
        NodeValue* left=largestBST(root->left);
        NodeValue* right=largestBST(root->right);
        
        if(root->val>left->maxNode && root->val<right->minNode)
        {
            int currSum = left->sum + right->sum + root->val;
            maxSum = max(maxSum, currSum);
            return new NodeValue(max(root->val,right->maxNode),min(root->val,left->minNode),
            currSum);
        }
        return new NodeValue(INT_MAX,INT_MIN,0);
        
    }

    int maxSumBST(TreeNode* root) {
        NodeValue* ans=largestBST(root);
        return maxSum;
    }
};