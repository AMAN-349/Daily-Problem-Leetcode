class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        while(k--)
        {
            long long pos=max_element(gifts.begin(),gifts.end())-gifts.begin();
            long long ele=*max_element(gifts.begin(),gifts.end());
            long long ans=sqrt(ele);
            gifts[pos]=ans;
        }
        long long res=accumulate(gifts.begin(),gifts.end(),0LL);
        return res;
    }
};