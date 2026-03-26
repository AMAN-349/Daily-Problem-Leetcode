class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>> v;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b)
        {
            int sum1=0;
            int sum2=0;
            int temp=a.first;
            int temp2=b.first;
            while(temp>0)
            {
                sum1+=temp%10;
                temp=temp/10;
            }
            while(temp2>0)
            {
                sum2+=temp2%10;
                temp2=temp2/10;
            }
            if(sum1==sum2)
            {
                return a.first<b.first;
            }
            return sum1<sum2;
        });

        int ans=0;

        for(int i=0;i<n;)
        {
            if(v[i].second==i)
            {
                i++;
                continue;
            }
            int correctpos=v[i].second;
            swap(v[i],v[correctpos]);
            ans++;
        }
        return ans;
    }
};