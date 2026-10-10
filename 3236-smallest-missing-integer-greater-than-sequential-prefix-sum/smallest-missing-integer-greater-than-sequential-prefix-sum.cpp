class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Step 1: Find the sum of the longest sequential prefix
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break; // Stop as soon as the sequence breaks
            }
        }
        
        // Step 2: Put all elements in a set for O(1) lookups
        unordered_set<int> s(nums.begin(), nums.end());
        
        // Step 3: Find the smallest integer >= sum that is NOT in the set
        int x = sum;
        while (s.count(x)) {
            x++;
        }
        
        return x;
    }
};