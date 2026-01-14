class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        unordered_map<char,int> m;
        int i=0;
        int j=0;
        int maxfreq=0;
        int ans=0;
        while(j<n)
        {
            m[answerKey[j]]++;
            maxfreq=max(maxfreq,m[answerKey[j]]);
            while(j-i+1-maxfreq>k)
            {
                if(m[answerKey[i]])
                m[answerKey[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};