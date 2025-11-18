class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<int> temp;
        vector<string> ans;
        for(int i=1;i<=min(n,target[target.size()-1]);i++)
        {
            temp.push_back(i);
            ans.push_back("Push");
        }
        int i=0;
        int j=0;
        int k=0;
        while(i<target.size() && j<temp.size())
        {
            if(target[i]==temp[j])
            {
                i++;
                j++;
            }
            else{
                int temp;
                temp=k+j+1;
                ans.insert(ans.begin() + temp,"Pop");
                j++;
                k++;
            }
        }
        return ans;

    }
};