class FoodRatings {
public:
    unordered_map<string, pair<string,int>> m1;
    unordered_map<string, set<pair<int,string>>> m2;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            m1[foods[i]] = {cuisines[i], ratings[i]};
            m2[cuisines[i]].insert({-ratings[i], foods[i]}); 
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = m1[food];
        m2[cuisine].erase({-oldRating, food});
        m2[cuisine].insert({-newRating, food});
        m1[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        return m2[cuisine].begin()->second; 
    }
};
