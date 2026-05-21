class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++)
        {
            int num=arr1[i];
            vector<int> temp;
            while(num>0)
            {
                temp.push_back(num%10);
                num=num/10;
            }
            reverse(temp.begin(),temp.end());
            int curr=temp[0];
            s.insert(curr);
            for(int i=1;i<temp.size();i++)
            {
                curr=curr*10+temp[i];
                s.insert(curr);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int num=arr2[i];
            vector<int> temp;
            while(num>0)
            {
                temp.push_back(num%10);
                num=num/10;
            }
            reverse(temp.begin(),temp.end());
            int curr=0;
            for(int i=0;i<temp.size();i++)
            {
                curr=curr*10+temp[i];
                if(s.find(curr)!=s.end())
                {
                    ans=max(ans,i+1);
                }
            }
        }
        return ans;
    }
};