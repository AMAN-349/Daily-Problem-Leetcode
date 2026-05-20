class Solution {
public:

    int find(vector<int>& v1,vector<int>& v2)
    {
        int cnt=0;
        for(int i=0;i<v1.size();i++)
        {
            cnt+=min(v1[i],v2[i]);
        }
        return cnt;
    }

    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        vector<int> v1(51,0);
        vector<int> v2(51,0);
        int n=A.size();
        for(int i=0;i<n;i++)
        {
            v1[A[i]]++;
            v2[B[i]]++;
            ans.push_back(find(v1,v2));
        }
        return ans;
    }
};