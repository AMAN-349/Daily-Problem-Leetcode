class Solution {
public:
    std::vector<int> hours = {1, 2, 4, 8}, minutes = {1, 2, 4, 8, 16, 32};

    void ans(std::vector<std::string>& res, std::pair<int, int> time, int turnedOn, int start) {
        if (turnedOn == 0) {
            res.push_back(std::to_string(time.first) + (time.second < 10 ? ":0" : ":") + std::to_string(time.second));
            return;
        }

        for (int i = start; i < hours.size() + minutes.size(); i++) {
            if (i < hours.size()) {
                time.first += hours[i];
                if (time.first < 12) {
                    ans(res, time, turnedOn - 1, i + 1);
                }
                time.first -= hours[i];
            } else {
                time.second += minutes[i - hours.size()];
                if (time.second < 60) {
                    ans(res, time, turnedOn - 1, i + 1);
                }
                time.second -= minutes[i - hours.size()];
            }
        }
    }

    std::vector<std::string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> res;
        ans(res, std::make_pair(0, 0), turnedOn, 0);
        return res;
    }
};
