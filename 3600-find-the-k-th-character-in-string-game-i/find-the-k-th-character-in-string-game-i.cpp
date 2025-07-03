class Solution {
public:
    char kthCharacter(int k) {
        string temp="a";
        while(temp.size()<=k)
        {
            string temp2=temp;
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]=='z')
                {
                    temp2+="a";
                }
                else{
                    temp2 = temp2 + char(temp[i] + 1);
                }
            }
            temp=temp2;
        }
        cout<<temp;
        return temp[k-1];
    }
};