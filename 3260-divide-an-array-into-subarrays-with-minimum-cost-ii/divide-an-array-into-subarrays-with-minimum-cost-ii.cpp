class Solution {
public:
    multiset<int> small;
    multiset<int> large;
    long long sum=0;
    int K=0;
    long long findMin(int y,int x)
    {
        bool insert=true;
        if (small.empty() || x <= *small.rbegin()) {
            small.emplace(x);
            sum += x;
        } 
        else {
            large.emplace(x);
        }
        

        auto it_small = small.find(y);
        if (it_small != small.end()) {
            small.erase(it_small);
            sum -= y;
        } else {
            auto it_large = large.find(y);
            if (it_large != large.end()) {
                large.erase(it_large);
            }
        }


        while(small.size()>K-2)
        {
            auto it = prev(small.end());
            large.emplace(*it);
            sum -= *it;
            small.erase(it);
        }

        while(small.size()<K-2)
        {
            auto it=large.begin();
            small.emplace(*it);
            sum+=*it;
            large.erase(it);
        }

        return sum;
    }

    long long minimumCost(vector<int>& nums, int k, int dist) {
        K=k;
        int n=nums.size();
        long long ans=LLONG_MAX;
        long long cost1=nums[0];
        long long cost2=nums[k-1];
        long long cost3=0;
        for(int j=1;j<k-1;j++)
        {
            large.insert(nums[j]);
        }
        while (small.size() < K-2) {
            auto it = large.begin();
            sum += *it;
            small.insert(*it);
            large.erase(it);
        }
        ans = min(ans, cost1 + cost2 + sum);
        for (int i = k; i < n; i++) {
            int outIdx = i - dist - 1;
            int inIdx = i - 1;

            if(outIdx>0)
            {
                findMin(nums[outIdx],nums[inIdx]);
                ans = min(ans, sum + nums[i] + nums[0]);
            }
            else{
                findMin(INT_MAX,nums[inIdx]);
                ans = min(ans, sum + nums[i] + nums[0]);
            }
        }

        return ans;
    }
};