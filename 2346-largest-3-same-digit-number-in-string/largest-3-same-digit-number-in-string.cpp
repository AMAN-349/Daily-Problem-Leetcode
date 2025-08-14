class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        string temp = "";
        temp += num[0];
        int cnt = 1;
        for(int i = 1; i < num.size(); i++) {
            if(num[i] != num[i-1] || cnt==3) {
                cout<<temp<<" ";
                if(cnt == 3) {
                    if(ans==""){
                        ans = temp;
                    }
                    else{
                        if(temp[0]>ans[0])
                        {
                            ans=temp;
                        }
                    }
                }
                temp = "";
                temp += num[i];
                cnt = 1;
            }
            else {
                temp += num[i];
                cnt++;
            }
        }
        if(cnt == 3) {
            if(ans==""){
                ans = temp;
            }
            else{
                if(temp[0]>ans[0])
                {
                    ans=temp;
                }
            }
        }

        return ans;
    }
};