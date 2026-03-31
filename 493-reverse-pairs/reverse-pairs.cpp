class Solution {
public:
    vector<int> temp;
    int merge(int st1,int e1,int st2,int e2,vector<int>& nums)
    {
        int i=st1;
        int j=st2;
        int ind=0;
        int cnt=0;
        int k=st1;
        for(int k2=st2;k2<=e2;k2++)
        {
            while(k<=e1 && (long long)nums[k]<=1LL*2*nums[k2])
            {
                k++;
            }
            cnt+=(e1-k+1);
        }

        while(i<=e1 && j<=e2)
        {
            if(nums[i]<=nums[j])
            {
                temp[ind++]=nums[i++];
            }
            else{
                temp[ind++]=nums[j++];
            }
        }
        while(i<=e1)
        {
            temp[ind++]=nums[i++];
        }
        while(j<=e2)
        {
            temp[ind++]=nums[j++];
        }

        for(int i = st1; i <= e2; i++)
        {
            nums[i] = temp[i - st1];
        }

        return cnt;
    }

    int mergesort(int l,int r,vector<int>& nums)
    {
        int cnt=0;
        if(l<r)
        {
            int mid=(l+r)/2;
            cnt+=mergesort(l,mid,nums);
            cnt+=mergesort(mid+1,r,nums);
            cnt+=merge(l,mid,mid+1,r,nums);
        }
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        //here we count all the inversions
        int n=nums.size();
        temp.resize(n,0);
        return mergesort(0,n-1,nums);
    }
};