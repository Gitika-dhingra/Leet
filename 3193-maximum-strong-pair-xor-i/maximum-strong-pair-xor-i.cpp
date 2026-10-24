
#include <vector>

class Solution {
public:
    // Function to calculate the maximum XOR of strong pairs in a vector.
    int maximumStrongPairXor(std::vector<int>& nums) {
        int ans = 0;

        // Iterate through each pair of numbers in the vector.
        for (auto x : nums) {
            for (auto y : nums) {
                // Check if the pair (x, y) is a strong pair.
                if (abs(x - y) <= std::min(x, y)) {
                    // Update the maximum XOR value.
                    ans = std::max(ans, x ^ y);
                }
            }
        }

        // Return the maximum XOR value of strong pairs.
        return ans;
    }
};
