class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int curr=1;
        int i=0;
        while(i<n){
            ans.push_back(curr);
            if(curr*10<=n)
            {
                curr*=10;
            }
            else{
                while(curr%10==9 || curr>=n)
                {
                    curr=curr/10;
                }
                curr+=1;
            }
            i++;
        }
        return ans;
    }
};