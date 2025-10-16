class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        map<int,int> m;
        for(auto i:nums)
        {
            if(i>=0)
            {
                m[i%value]++;
            }
            else{
                int ans=(abs(i)/value);
                int ans2=abs(i%value);
                if(ans2!=0)
                {
                    ans+=1;
                }
                int temp=value*ans;
                m[i+temp]+=1;
            }
        }
        set<int> s;
        for(auto i:m)
        {
            int temp=i.first;
            int cnt=i.second;
            while(cnt--)
            {
                if(temp>=0){
                    s.insert(temp);
                }
                temp+=value;
            }
        }
        int pt=0;
        for(auto i:s)
        {
            cout<<i<<" ";
            if(i!=pt)
            {
                return pt;
            }
            pt++;
        }
        return pt;

    }
};