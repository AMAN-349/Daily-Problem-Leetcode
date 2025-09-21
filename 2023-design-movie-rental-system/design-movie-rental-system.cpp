class MovieRentingSystem {
public:

    unordered_map<int,set<vector<int>>> movies;
    set<vector<int>> rented;
    unordered_map<string, int> priceMap;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto i:entries)
        {
            int shop=i[0];
            int movie=i[1];
            int price=i[2];
            movies[movie].insert({price,shop});
            string temp=to_string(shop)+to_string(movie);
            priceMap[temp]=price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        for(auto i:movies[movie])
        {
            ans.push_back(i[1]);
            if(ans.size()==5)
            {
                return ans;
            }
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        string temp=to_string(shop)+to_string(movie);
        int price = priceMap[temp];
        movies[movie].erase({price,shop});
        rented.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        string temp=to_string(shop)+to_string(movie);
        int price = priceMap[temp];
        rented.erase({price,shop,movie});
        movies[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for(auto i: rented)
        {
            ans.push_back({i[1],i[2]});
            if(ans.size()==5)
            {
                return ans;
            }
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */