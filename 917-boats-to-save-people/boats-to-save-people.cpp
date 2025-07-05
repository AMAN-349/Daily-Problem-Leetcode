class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int l=0;
        int r=n-1;
        int cnt=0;
        while(l<=r)
        {
            if(l==r)
            {
                cnt++;
                break;
            }
            if(people[l]+people[r]<=limit)
            {
                cnt++;
                l++;
                r--;
            }
            else{
                if(people[l]<people[r])
                {
                    cnt++;
                    r--;
                }
                else{
                    cnt++;
                    l++;
                }
            }
        }
        return cnt;

    }
};