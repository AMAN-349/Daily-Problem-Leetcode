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
class BSTIterator{
    stack<TreeNode*> st;
    bool reverse;
    public:
        BSTIterator(TreeNode* root,bool isReverse)
        {
            reverse=isReverse;
            pushAll(root);
        }

        int next()
        {
            TreeNode* temp=st.top();
            st.pop();
            if(reverse)
            {
                pushAll(temp->left);
            }
            else{
                pushAll(temp->right);
            }
            return temp->val;
        }

        void pushAll(TreeNode* temp)
        {
            while(temp)
            {
                st.push(temp);
                if(reverse==true)
                {
                    temp=temp->right;
                }
                else{
                    temp=temp->left;
                }
            }
        }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        //here we solve in TC: O(N) and SC:O(H)
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k)
            {
                return true;
            }
            else if(i+j<k)
            {
                i=l.next();
            }
            else{
                j=r.next();
            }
        }
        return false;


    }
};