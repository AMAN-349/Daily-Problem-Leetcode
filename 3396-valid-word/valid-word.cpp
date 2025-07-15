class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)
        {
            return false;
        }
        int cnt=0,cnt1=0;
        for(int i=0;i<word.size();i++)
        {
            cout<<"**"<<" ";
            if((word[i]>='0' && word[i]<='9') || (word[i]>='A' && word[i]<='z') || (word[i] >= 'A' && word[i] <= 'Z'))
            {
                char ch = tolower(word[i]);
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                {
                    cnt++;
                }
                else if(!(word[i]>='0' && word[i]<='9'))
                {
                    cnt1++;
                }
            }
            else{
                return false;
            }
        }
        return (cnt>0) && (cnt1>0);
    }
};