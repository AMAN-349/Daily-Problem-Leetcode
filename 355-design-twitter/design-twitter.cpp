class Twitter {
public:

    static bool cmp(pair<int,int> p1,pair<int,int> p2)
    {
        return p1.second>p2.second;
    }

    map<int, vector<pair<int,int>>> m;  
    map<int, vector<int>> followers;  
    int time=1;
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        m[userId].push_back({tweetId,time});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> feed;
        for (auto tweet : m[userId]) {
            feed.push_back(tweet);
        }

        for (auto followerId : followers[userId]) {
            for (auto tweet : m[followerId]) {
                feed.push_back(tweet);
            }
        }
        sort(feed.begin(),feed.end(),cmp);
        vector<int> ans;
        int n=feed.size();
        for(int i=0;i<min(n,10);i++)
        {
            ans.push_back(feed[i].first);
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        auto &flw = followers[followerId];
        if (find(flw.begin(), flw.end(), followeeId) != flw.end()) return;
        followers[followerId].push_back(followeeId);  
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;  
        auto& followerList = followers[followerId];
        followerList.erase(remove(followerList.begin(), followerList.end(), followeeId), followerList.end());
    }
};

