class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int prod;

        //0 pos
        prod=nums[0]*nums[1]*nums[2];

        //1 pos
        prod=max(prod,nums[n-1]*nums[n-2]*nums[n-3]);

        prod=max(prod,nums[0]*nums[1]*nums[n-1]);

        //2 pos
        if(n>3)
        prod=max(prod,nums[n-2]*nums[n-3]*nums[n-4]);

        return prod;




    }
};