/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
        {
            return "";
        }
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* tmp=q.front();
            q.pop();
            if(tmp==NULL)
            {
                ans+="#,";
            }
            else{
                ans.append(to_string(tmp->val)+",");
            }
            if(tmp)
            {
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
        {
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* tmp=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
            {
                tmp->left=NULL;
            }
            else{
                TreeNode* leftnode=new TreeNode(stoi(str));
                tmp->left=leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str=="#")
            {
                tmp->right=NULL;
            }
            else{
                TreeNode* rightnode=new TreeNode(stoi(str));
                tmp->right=rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));