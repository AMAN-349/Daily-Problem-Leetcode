class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int> freq(26);
        for(auto i:word)
        {
            int ch=i-'a';
            freq[ch]++;
        }
        sort(freq.begin(),freq.end(),greater<int>());

        for(auto i:freq)
        {
            cout<<i<<" ";
        }

        int currpush=1;
        int cnt=0;
        int ans=0;
        for(int i=0;i<freq.size();i++)
        {
            if(freq[i]==0) break;
            ans+=(freq[i]*currpush);
            cnt++;
            if(cnt%8==0)
            {
                currpush++;
            }
        }

        return ans;
    }
};