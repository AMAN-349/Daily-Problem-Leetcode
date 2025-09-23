class Solution {
public:

    vector<int> split(string ver) {
        vector<int> ans;
        string temp = "";
        
        for (auto i : ver) {
            if (i == '.') {
                int j = 0;
                while (j < temp.size() && temp[j] == '0') {
                    j++;
                }
                ans.push_back(j == temp.size() ? 0 : stoi(temp.substr(j)));
                temp = "";
            } else {
                temp += i;
            }
        }
        if (!temp.empty()) {
            int j = 0;
            while (j < temp.size() && temp[j] == '0') {
                j++;
            }
            ans.push_back(j == temp.size() ? 0 : stoi(temp.substr(j)));
        }

        return ans;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1=split(version1);
        vector<int> v2=split(version2);
        int n=v1.size();
        int m=v2.size();
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(v1[i]>v2[j])
            {
                return 1;
            }
            else if(v1[i]<v2[j])
            {
                return -1;
            }
            i++;
            j++;
        }
        while(i<n)
        {
            if(v1[i]!=0)
            {
                return 1;
            }
            i++;
        }
        while(j<m)
        {
            if(v2[j]!=0)
            {
                return -1;
            }
            j++;
        }
        return 0;
    }
};