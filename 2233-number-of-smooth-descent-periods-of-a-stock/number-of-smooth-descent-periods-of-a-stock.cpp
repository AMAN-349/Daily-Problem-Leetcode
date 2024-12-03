// class Solution {
// public:

//     void find(vector<int>& prices,vector<int> temp,int &ans,int i,int n)
//     {
//         if(i>=n)
//         {
//             return;
//         }
//         if(temp.size()==0)
//         {
//             temp.push_back(prices[i++]);
//             ans++;
//             find(prices,temp,ans,i,n);
//         }
//         else{
//             int res=temp.back();
//             if((prices[i]+1)==res)
//             {
//                 temp.push_back(prices[i++]);
//                 ans++;
//                 find(prices,temp,ans,i,n);
//             }
//             else{
//                 return;
//             }
//         }

//     }

//     long long getDescentPeriods(vector<int>& prices) {
//         int ans=0;
//         int n=prices.size();
//         vector<int> v;
//         for(int i=0;i<prices.size();i++)
//         {
//             find(prices,v,ans,i,n);
//         }
//         return ans;
//     }

    
// };

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) 
    {
        long long ans = 0, num = 1;

        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i] - prices[i-1] == -1) ++num;
            else
            {
                ans += num * (num+1) / 2;
                num = 1;
            }
        }

        ans += num * (num+1) / 2;

        return ans == 0 ? 1: ans;
    }
};
