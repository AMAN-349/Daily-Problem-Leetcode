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

    TreeNode* findPar(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& m,int start)
    {
        queue<TreeNode*> q;
        q.push(root);
        m[root]=NULL;
        TreeNode* res;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->val==start)
            {
                res=temp;
            }
            if(temp->left)
            {
                m[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                m[temp->right]=temp;
                q.push(temp->right);
            }
        }
        return res;
    }

    int amountOfTime(TreeNode* root, int start) {
        //firstly created the parent map
        unordered_map<TreeNode*,TreeNode*> m;
        TreeNode* res=findPar(root,m,start);
        cout<<res->val;
        int maxi=0;
        //now start infected the tree using bfs
        queue<TreeNode*> q;
        unordered_map<TreeNode*,int> vis;
        q.push(res);
        vis[res]=1;
        while(!q.empty())
        {
            int sz=q.size();
            int fl=0;
            for(int i=0;i<sz;i++)
            {
                TreeNode* temp=q.front();
                q.pop();

                if(temp->left && !vis[temp->left])
                {
                    fl=1;
                    vis[temp->left]=1;
                    q.push(temp->left);
                }

                if(temp->right && !vis[temp->right])
                {
                    fl=1;
                    vis[temp->right]=1;
                    q.push(temp->right);
                }

                if(m[temp] && !vis[m[temp]])
                {
                    fl=1;
                    vis[m[temp]]=1;
                    q.push(m[temp]);
                }
            }
            if(fl)
            {
                maxi++;
            }
        }
        return maxi;
    }
};