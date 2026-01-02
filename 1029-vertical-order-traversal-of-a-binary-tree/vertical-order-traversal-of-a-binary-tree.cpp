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

    struct Node{
        int data;
        int l;
        int hd;
        Node(int val,int ld,int h) {
            data = val;
            l = ld;
            hd = h;
        }
    };

    static bool cmp(Node n1,Node n2)
    {
        if(n1.l==n2.l && n1.hd==n2.hd)
        {
            return n1.data<n2.data;
        }
        if(n1.hd==n2.hd)
        {
            return n1.l<n2.l;
        }
        return n1.hd<n2.hd;
    }

    void find(TreeNode* root,int l,int hd,vector<Node>& ans)
    {
        if(!root)
        {
            return;
        }
        Node temp(root->val,l,hd);
        ans.push_back(temp);
        find(root->left,l+1,hd-1,ans);
        find(root->right,l+1,hd+1,ans);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<Node> ans;
        find(root,0,0,ans);
        sort(ans.begin(),ans.end(),cmp);
        vector<vector<int>> res;
        map<int,vector<int>> m;
        for(auto i:ans)
        {
            int temp=i.hd;
            m[temp].push_back(i.data);
        }
        for(auto i:m)
        {
            res.push_back(i.second);
        }
        return res;
    }
};