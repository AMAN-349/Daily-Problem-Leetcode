class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;       // Start with the first element
        int step = 1;       // Step size
        bool left = true;   // Direction of elimination
        int remaining = n;  // Number of elements remaining

        while (remaining > 1) {
            // Update the head only if eliminating from the left or the number of elements is odd
            if (left || remaining % 2 == 1) {
                head += step;
            }
            // Update for the next round
            remaining /= 2;
            step *= 2;
            left = !left;   // Alternate the direction
        }

        return head;
    }
};
