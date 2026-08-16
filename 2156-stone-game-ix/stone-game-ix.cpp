class Solution {
public:
    bool solve(int counts[3], int current_sum_mod, int stones_picked, int total_stones) {
        if (stones_picked == total_stones) {
            return stones_picked % 2 != 0; 
        }
        
        for (int i = 0; i < 3; i++) {
            if (counts[i] > 0) {
                int next_sum_mod = (current_sum_mod + i) % 3;
                
                if (next_sum_mod == 0) continue;
                
                counts[i]--;
                bool opponent_wins = solve(counts, next_sum_mod, stones_picked + 1, total_stones);
                
                counts[i]++; 
                
                if (!opponent_wins) {
                    return true; 
                }
            }
        }
        
        return false;
    }

    bool stoneGameIX(vector<int>& stones) {
        int counts[3] = {0};
        for (int stone : stones) {
            counts[stone % 3]++;
        }
        
        counts[0] %= 2;
        int total_stones = counts[0] + counts[1] + counts[2];
        return solve(counts, 0, 0, total_stones);
    }
};