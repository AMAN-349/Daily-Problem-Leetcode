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
    int widthOfBinaryTree(TreeNode* root) {
        //here we do the level order traversal
        queue<pair<TreeNode*,long long>> q;
        int ans=0;
        q.push({root,0});
        int minm=0;
        while(!q.empty())
        {
            int sz=q.size();
            minm=q.front().second;
            int first,last;
            for(int i=0;i<sz;i++)
            {
                pair<TreeNode*,long long> temp=q.front();
                q.pop();
                if(i==0)
                {
                    first=temp.second;
                }
                if(i==sz-1)
                {
                    last=temp.second;
                }
                if(temp.first->left)
                {
                    q.push({temp.first->left,((2LL*(temp.second-minm))+1)});
                }
                if(temp.first->right)
                {
                    q.push({temp.first->right,((2LL*(temp.second-minm))+2)});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};