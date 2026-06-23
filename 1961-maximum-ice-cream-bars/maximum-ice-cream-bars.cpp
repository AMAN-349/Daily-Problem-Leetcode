class Solution {
public:

    void sortarray(vector<int>& arr)
    {
        int n = arr.size();

        int maxval = 0;
        for (int i = 0; i < n; i++)
            maxval = max(maxval, arr[i]);

        vector<int> cntArr(maxval + 1, 0);

        for (int i = 0; i < n; i++)
            cntArr[arr[i]]++;

        for (int i = 1; i <= maxval; i++)
            cntArr[i] += cntArr[i - 1];

        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[cntArr[arr[i]] - 1] = arr[i];
            cntArr[arr[i]]--;
        }

        arr=ans;

    }

    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        sortarray(costs);
        int ans=0;
        for(auto i:costs)
        {
            if(coins>=i)
            {
                ans++;
                coins-=i;
            }
            else{
                break;
            }
        }
        return ans;
    }
};