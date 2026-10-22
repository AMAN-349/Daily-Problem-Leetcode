class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> org=nums;
        sort(nums.begin(),nums.end());
        vector<int> inc=nums;
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int> dec=nums;
        int n=nums.size();

        if(inc==org) return 0;
        if(dec==org) return 1;

        int ind1=-1;
        for(int i=1;i<n;i++)
        {
            if(org[i]<org[i-1])
            {
                ind1=i;
                break;
            }
        }
        vector<int> temp1=org;
        reverse(temp1.begin(),temp1.begin()+ind1);
        reverse(temp1.begin()+ind1,temp1.end());
        reverse(temp1.begin(),temp1.end());

        int ind2=-1;

        for(int i=1;i<n;i++)
        {
            if(org[i]>org[i-1])
            {
                ind2=i;
                break;
            }
        }
        vector<int> temp2=org;
        reverse(temp2.begin(),temp2.begin()+ind2);
        reverse(temp2.begin()+ind2,temp2.end());
        reverse(temp2.begin(),temp2.end());

        if(temp1!=inc && temp2!=dec)
        {
            return -1;
        }

        if(temp1==inc)
        {
            cout<<ind1<<" ";
            if(ind1==n-1)
            {
                return min(ind1,3);
            }
            int ans1=2+(n-ind1);
            return min(ans1,ind1);
        }
        cout<<ind2<<" ";

        if(ind2==n-1)
        {
            return 2;
        }

        int ans1=1+(n-ind2);

        return min(ans1,ind2+1);

    }
};