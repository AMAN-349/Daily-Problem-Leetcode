/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode*,TreeNode*> findPar(TreeNode* root)
    {
        unordered_map<TreeNode*,TreeNode*> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)
            {
                ans[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                ans[temp->right]=temp;
                q.push(temp->right);
            }
        }

        return ans;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> par=findPar(root);
        unordered_map<TreeNode*, bool> vis;
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        vis[target]=true;
        vector<int> ans;
        while(!q.empty())
        {
            pair<TreeNode*,int> temp=q.front();
            int chk = temp.second;
            q.pop();
            if(chk==k)
            {
                ans.push_back(temp.first->val);
            }

            if(temp.first->left && chk<k && !vis[temp.first->left])
            {
                q.push({temp.first->left,temp.second+1});
                vis[temp.first->left]=true;
            }
            if(temp.first->right && chk<k && !vis[temp.first->right])
            {
                q.push({temp.first->right,temp.second+1});
                vis[temp.first->right]=true;
            }
            if(par[temp.first] && chk<k && !vis[par[temp.first]])
            {
                q.push({par[temp.first], temp.second+1});
                vis[par[temp.first]]=true;
            }
        }
        return ans;
    }
};