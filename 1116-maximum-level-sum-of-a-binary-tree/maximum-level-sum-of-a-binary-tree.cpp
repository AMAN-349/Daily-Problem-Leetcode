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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int ans=INT_MIN;
        int a=0;
        int ans2=0;
        while(q.empty()==false)
        {
            int s=q.size();
            int sum=0;
            a++;
            for(int i=0;i<s;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            if(sum>ans)
            {
                ans=sum;
                ans2=a;
            }
        }
        return ans2;
    }
};