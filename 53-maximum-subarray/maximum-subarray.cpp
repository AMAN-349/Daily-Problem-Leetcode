class Solution {
public:
    //dap means divide and conquer

    int dap(vector<int>& nums,int i,int j)
    {
        if(i>j)
        {
            return INT_MIN;
        }
        int m=(i+j)/2;
        int suml=dap(nums,i,m-1);
        int sumr=dap(nums,m+1,j);
        int summ=nums[m];
        int k=m-1;
        int curr=summ;
        while(k>=i)
        {
            curr+=nums[k];
            summ=max(summ,curr);
            k--;
        }
        k=m+1;
        curr=summ;
        while(k<=j)
        {
            curr+=nums[k];
            summ=max(summ,curr);
            k++;
        }
        return max({suml,summ,sumr});
    }

    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        return dap(nums,0,n-1);
    }
};