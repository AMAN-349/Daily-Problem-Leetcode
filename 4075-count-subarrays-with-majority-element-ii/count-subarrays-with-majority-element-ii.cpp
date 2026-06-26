#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long ans=0;
        int n=nums.size();

        vector<int> prefsum(n,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                prefsum[i]=1;
            }
            else{
                prefsum[i]=-1;
            }
        }

        for(int i=1;i<n;i++)
        {
            prefsum[i]+=prefsum[i-1];
        }

        ordered_set<pair<int,int>> st;
        st.insert({0,0});
        for(int i=0;i<n;i++)
        {
            ans+=st.order_of_key({prefsum[i],-1});
            st.insert({prefsum[i],i});
        }
        return ans;
    }
};