class NumArray {
public:

    void updateval(int i,int val)
    {
        for(;i<n;i+=(i&-i))
        {
            bit[i]+=val;
        }
    }

    vector<int> bit;
    vector<int> v;
    int n;
    NumArray(vector<int>& nums) {
        v=nums;
        n=nums.size();
        n+=2;
        bit.resize(n,0);
        for(int i=0;i<nums.size();i++)
        {
            updateval(i+1,nums[i]);
        }
    }
    
    void update(int index, int val) {
        updateval(index+1,val-v[index]);
        v[index]=val;
    }

    int sum(int i)
    {
        int ans=0;
        for(;i>0;i-=(i&-i))
        {
            ans+=bit[i];
        }
        return ans;
    }
    
    int sumRange(int left, int right) {
        return sum(right+1)-sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */