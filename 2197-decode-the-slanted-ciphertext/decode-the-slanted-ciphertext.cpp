class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        if(rows==1)
        {
            return encodedText;
        }
        int cols=n/rows;

        vector<vector<char>> temp(rows,vector<char>(cols));
        int ptr=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                temp[i][j]=encodedText[ptr++];
            }
        }

        string ans="";

        for(int i=0;i<cols;i++)
        {
            int p1=0;
            int p2=i;
            while(p1<rows && p2<cols)
            {
                ans+=temp[p1][p2];
                p1++;
                p2++;
            }
        }
        while(!ans.empty() && ans.back()==' ')
        {
            ans.pop_back();
        }
        return ans;


    }
};