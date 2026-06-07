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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        TreeNode* root;
        unordered_set<int> child;
        for(auto i:descriptions)
        {
            if(mp.find(i[0])==mp.end())
            {
                mp[i[0]]=new TreeNode(i[0]);
            }
            if(mp.find(i[1])==mp.end())
            {
                mp[i[1]]=new TreeNode(i[1]);
            }
            int chl=i[1];
            child.insert(chl);
        }

        for(auto i:descriptions)
        {
            int par=i[0];
            int chl=i[1];

            if(child.find(par)==child.end()) root=mp[par];

            if(i[2])
            {
                mp[par]->left=mp[chl];
            }
            else{
                mp[par]->right=mp[chl];
            }
        }
        return root;
    }
};