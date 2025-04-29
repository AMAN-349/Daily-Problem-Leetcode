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

    map<TreeNode*,TreeNode*> findpar(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode*,TreeNode*> m;
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left)
            {
                m[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                m[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return m;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> m=findpar(root);
        map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int curr=0;
        while(!q.empty())
        {
            int size=q.size();
            if(curr++==k) break;
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(m[curr] && !visited[m[curr]])
                {
                    q.push(m[curr]);
                    visited[m[curr]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};