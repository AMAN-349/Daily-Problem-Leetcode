class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans;
        for(int i=n;i>0;i--)
        {
            auto maxi=max_element(arr.begin(),arr.begin()+i);
            if(maxi==arr.begin()+(i-1))
            {
                continue;
            }
            if(maxi==arr.begin())
            {
                ans.push_back(i);
                reverse(arr.begin(),arr.begin()+i);
            }
            else{
                ans.push_back(maxi-arr.begin()+1);
                reverse(arr.begin(),maxi+1);
                ans.push_back(i);
                reverse(arr.begin(),arr.begin()+i);
            }
        }
        return ans;
    }
};