class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end(),greater<int>());
        int temp=0;
        int cnt=0;
        for(auto i:capacity)
        {
            temp+=i;
            cnt++;
            if(temp>=sum)
            {
                break;
            }
        }
        return cnt;
    }
};