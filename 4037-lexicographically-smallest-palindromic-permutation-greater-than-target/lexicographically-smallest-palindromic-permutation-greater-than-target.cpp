class Solution {
public:
    string lexPalindromicPermutation(string s, string target)
    {
        int n = s.size();

        map<char,int> mp;

        for(auto i : s)
        {
            mp[i]++;
        }

        int cnt = 0;
        char ch = '0';

        for(auto i : mp)
        {
            if(i.second % 2 != 0)
            {
                ch = i.first;
                cnt++;
            }
        }

        if(cnt > 1)
            return "";

        string curr(n/2,'#');
        int sz = n/2;

        if(n%2 != 0)
        {
            sz--;
        }

        if(n % 2 == 1)
        {
            mp[ch]--;

            if(mp[ch] == 0)
                mp.erase(ch);
        }

        string ans = "";

        for(int i = 0; i < n/2; i++)
        {
            char target_c = target[i]; 

            auto it = mp.lower_bound(target_c);

            if(it == mp.end())
            {
                for(int j = i-1; j >= 0; j--)
                {
                    if(ans.empty())
                        break;

                    mp[ans.back()] += 2;
                    ans.pop_back();

                    auto sit = mp.upper_bound(target[j]);

                    if(sit != mp.end())
                    {
                        ans += sit->first;

                        mp[sit->first] -= 2;

                        if(mp[sit->first] == 0)
                        {
                            mp.erase(sit->first);
                        }

                        for(auto p : mp)
                        {
                            while(p.second > 0)
                            {
                                ans += p.first;
                                p.second -= 2;
                            }
                        }

                        string tt=ans;
                        if(ch!='0') 
                        {
                            ans+=ch;
                        }
                        reverse(tt.begin(),tt.end());
                        ans+=tt;

                        return ans;
                    }
                }
                return "";
            }

            else if(it->first > target_c) 
            {
                ans += it->first;

                mp[it->first] -= 2;

                if(mp[it->first] == 0)
                {
                    mp.erase(it->first);
                }

                for(auto p : mp)
                {
                    while(p.second > 0)
                    {
                        ans += p.first;
                        p.second -= 2;
                    }
                }

                string tt=ans;
                if(ch!='0') 
                {
                    ans+=ch;
                }
                reverse(tt.begin(),tt.end());
                ans+=tt;

                return ans;
            }

            else
            {
                ans += it->first;

                mp[it->first] -= 2;

                if(mp[it->first] == 0)
                {
                    mp.erase(it->first);
                }
            }
        }

        string res=target.substr(0,n/2);

        string cp=ans;

        string tt = ans;
        if(ch != '0')
        {
            ans += ch;
        }
        
        reverse(tt.begin(), tt.end());
        ans += tt;
        if(ans>target)
        return ans;

        ans=cp;

        if(res == ans)
        {
            cout<<"hi";
            if(next_permutation(ans.begin(), ans.end()))
            {
                string tt = ans;
                if(ch != '0')
                {
                    ans += ch;
                }
                
                reverse(tt.begin(), tt.end());
                ans += tt;
                return ans;
            }
        }
        tt=ans;

        if(ch!='0')
        {
            ans+=ch;
        }
        reverse(tt.begin(),tt.end());
        ans+=tt;
        if(ans <= target) 
        {
            return "";
        }
        cout<<"hi";

        return ans;
    }
};