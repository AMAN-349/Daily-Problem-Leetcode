class Solution {
public:

vector<int> temp;

int merge(vector<int>& v, int s1, int e1, int s2, int e2)
{
    int c = s1;
    int i = s1;
    int j = s2;
    int cnt = 0;
    int k=s1;
    for(int k2=s2;k2<=e2;k2++)
    {
        while(k<=e1 && (long long)v[k]<=1LL*2*v[k2])
        {
            k++;
        }
        cnt+=(e1-k+1);
    }

    while(i <= e1 && j <= e2)
    {
        if(v[i] <= v[j])
        {
            temp[c++] = v[i++];
        }
        else
        {
            temp[c++] = v[j++];
        }
    }

    while(i <= e1) temp[c++] = v[i++];
    while(j <= e2) temp[c++] = v[j++];

    for(int k = s1; k <= e2; ++k)
        v[k] = temp[k];

    return cnt;
}

int mergesort(vector<int>& v, int l, int r)
{
    if(l >= r) return 0;

    int m = (l + r) / 2;
    int cnt = 0;
    cnt += mergesort(v, l, m);
    cnt += mergesort(v, m + 1, r);
    cnt += merge(v, l, m, m + 1, r);
    return cnt;
}

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        temp.assign(n, 0); 
        return mergesort(nums, 0, n - 1);
    }
};