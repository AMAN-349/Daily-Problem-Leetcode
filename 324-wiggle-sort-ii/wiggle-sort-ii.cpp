class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto i:nums)
        {
            pq.push(i);
        }
        int i=1;
        int n=nums.size();
        while(pq.size()>0 && i<n)
        {
            nums[i]=pq.top();
            pq.pop();
            i+=2;
        }
        i=0;
        while(pq.size()>0 && i<n)
        {
            nums[i]=pq.top();
            pq.pop();
            i+=2;
        }
    }
};