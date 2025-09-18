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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2== 0) return {};
        if(n == 1) return { new TreeNode(0) };
        vector<TreeNode*> ans;
        for(int i=0;i<n;i++)
        {
            vector<TreeNode*> lsts=allPossibleFBT(i);
            vector<TreeNode*> rsts=allPossibleFBT(n-1-i);

            for(int j=0;j<lsts.size();j++)
            {
                for(int k=0;k<rsts.size();k++)
                {
                    ans.push_back(new TreeNode(0,lsts[j],rsts[k]));
                }
            }
        }
        return ans;
    }
};