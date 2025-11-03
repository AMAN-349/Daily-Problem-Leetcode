class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=neededTime.size();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(colors[i]==colors[i-1]){
                vector<int> temp;
                while(i<n && colors[i]==colors[i-1])
                {
                    temp.push_back(neededTime[i-1]);
                    i++;
                }
                temp.push_back(neededTime[i-1]);
                int sum=accumulate(temp.begin(),temp.end(),0);
                sum-=*max_element(temp.begin(),temp.end());
                ans+=sum;
            }
        }
        return ans;
    }
};