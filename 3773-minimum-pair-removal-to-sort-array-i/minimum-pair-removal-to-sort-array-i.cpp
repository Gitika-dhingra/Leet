class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (true) {
            bool is_sorted = true;
            for (int i = 0; i < (int)nums.size() - 1; ++i) {
                if (nums[i] > nums[i + 1]) {
                    is_sorted = false;
                    break;
                }
            }

            if (is_sorted) {
                return operations;
            }

            int min_sum = INT_MAX;
            int min_idx = -1;

            for (int i = 0; i < (int)nums.size() - 1; ++i) {
                int sum = nums[i] + nums[i + 1];
                if (sum < min_sum) {
                    min_sum = sum;
                    min_idx = i;
                }
            }

            nums[min_idx] = min_sum;
            nums.erase(nums.begin() + min_idx + 1);

            operations++;
        }
    }
};