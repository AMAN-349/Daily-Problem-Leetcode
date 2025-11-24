class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%3==0)
        {
            return sum;
        }
        int rem=sum%3;
        sort(nums.begin(),nums.end());
        int neg=0;
        if(rem==1)
        {
            int temp=0;
            for(auto i:nums)
            {
                if(i%3==1)
                {
                    temp=i;
                    break;
                }
            }
            int temp2=0;
            int cnt=0;
            for(auto i:nums)
            {
                if(i%3==2)
                {
                    temp2+=i;
                    cnt++;
                }
                if(cnt==2)
                {
                    break;
                }
            }
            if(temp2==0 || cnt<2)
            {
                neg=temp;
            }
            else if(temp==0 && cnt<2)
            {
                neg=temp2;
            }
            else{
                neg=min(temp,temp2);
            }
        }
        else{
            int temp=0;
            for(auto i:nums)
            {
                if(i%3==2)
                {
                    temp=i;
                    break;
                }
            }
            int temp2=0;
            int cnt=0;
            for(auto i:nums)
            {
                if(i%3==1)
                {
                    cnt++;
                    temp2+=i;
                }
                if(cnt==2)
                {
                    break;
                }
            }
            if(temp2==0 || cnt<2)
            {
                neg=temp;
            }
            else if(temp==0 && cnt==2)
            {
                neg=temp2;
            }
            else{
                neg=min(temp,temp2);
            }
        }
        return sum-neg;


    }
};