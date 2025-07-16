class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                even.push_back(i);
            }
            else{
                odd.push_back(i);
            }
        }
        int ans=max(odd.size(),even.size());
        int i=0;int j=0,cnt1=0,cnt2=0;
        int temp=-1;
        bool flag=true;
        while(i<=even.size() && j<=odd.size())
        {
            if(flag)
            {
                if(i<even.size() && even[i]>temp)
                {
                    cnt1++;
                    temp=even[i];
                    flag=false;
                }
                cout<<temp<<" ";
                i++;
            }
            else{
                if(j<odd.size() && odd[j]>temp)
                {
                    cnt1++;
                    temp=odd[j];
                    flag=true;
                }
                cout<<temp<<" ";
                j++;
            }
        }
        ans=max(ans,cnt1);
        i=0;
        j=0;
        flag=false;
        temp=-1;
        while(i<=even.size() && j<=odd.size())
        {
            if(flag)
            {
                if(i<even.size() && even[i]>temp)
                {
                    cnt2++;
                    temp=even[i];
                    flag=false;
                }
                i++;
            }
            else{
                if(j<odd.size() && odd[j]>temp)
                {
                    cnt2++;
                    temp=odd[j];
                    flag=true;
                }
                j++;
            }
        }
        ans=max(ans,cnt2);
        return ans;
    }
};