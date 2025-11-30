class Solution {
public:

    int dorev(int n)
    {
        string temp="";
        while(n>0)
        {
            temp+=to_string(n%10);
            n=n/10;
        }
        int i=0;
        while(i<temp.size() && temp[i]=='0')
        {
            i++;
        }
        string ans=temp.substr(i);
        int res=stoi(ans);
        return res;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> org;
        unordered_map<int,int> rev;
        org[nums[0]]=0;
        int temp=dorev(nums[0]);
        rev[temp]=0;
        int ans=INT_MAX;
        for(int i=1;i<n;i++)
        {
            int curr=nums[i];
            int currev=dorev(nums[i]);
            // if(org.find(currev)!=org.end())
            // {
            //     ans=min(ans,i-org[currev]);
            // }
            if(rev.find(curr)!=rev.end())
            {
                ans=min(ans,i-rev[curr]);
            }
            org[curr]=i;
            rev[currev]=i;
        }
        for(auto i:org)
        {
            cout<<i.first<<" ";
        }
        for(auto i:rev)
        {
            cout<<i.first<<" ";
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};