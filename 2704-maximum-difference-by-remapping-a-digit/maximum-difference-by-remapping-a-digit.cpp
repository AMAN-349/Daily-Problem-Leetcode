class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> v;
        while(num>0)
        {
            v.push_back(num%10);
            num=num/10;
        }
        reverse(v.begin(),v.end());
        int i=0;
        while(i<v.size() && v[i]==9)
        {
            i++;
        }
        int temp;
        if(i<v.size())
        temp=v[i];
        vector<int> dup=v;
        for(int j=0;j<v.size();j++)
        {
            if(v[j]==temp){
                v[j]=9;
            }
        }
        temp=dup[0];
        for(int j=0;j<dup.size();j++)
        {
            if(dup[j]==temp){
                dup[j]=0;
            }
        }
        int num1=0;
        int num2=0;
        for(auto it:v)
        {
            num1=num1*10+it;
        }
        for(auto it:dup)
        {
            num2=num2*10+it;
        }
        cout<<num1<<" "<<num2;
        return num1-num2;
    }
};