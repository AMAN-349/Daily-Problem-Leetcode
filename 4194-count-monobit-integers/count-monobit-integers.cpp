class Solution {
public:
    int countMonobit(int n) {
        int k = floor(log2(n + 1));
        int temp = (1 << k) - 1;  
        cout<<temp<<" ";

        int count = 1;
        while (temp > 0) {
            count++;
            temp >>= 1;
        }
        return count;
    }
};
