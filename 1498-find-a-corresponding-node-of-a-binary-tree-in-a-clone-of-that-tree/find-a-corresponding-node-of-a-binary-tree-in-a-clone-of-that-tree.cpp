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

    TreeNode* find(TreeNode* temp1, TreeNode* temp2,TreeNode* target)
    {
        if(!temp1 || !temp2)
        {
            return NULL;
        }
        if(temp1==target)
        {
            return temp2;
        }
        TreeNode* ans1 = find(temp1->left,temp2->left,target);
        TreeNode* ans2 = find(temp1->right,temp2->right,target);
        return ans1==NULL?ans2:ans1;
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* temp1=original;
        TreeNode* temp2=cloned;
        return find(temp1,temp2,target);
    }
};