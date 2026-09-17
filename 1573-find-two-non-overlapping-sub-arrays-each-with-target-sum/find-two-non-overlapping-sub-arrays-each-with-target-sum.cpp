class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX / 2); 
        
        int result = INT_MAX;
        int current_sum = 0;
        int left = 0;
        int min_so_far = INT_MAX / 2;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];

            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }

            if (current_sum == target) {
                int len = right - left + 1;
                if (left > 0 && min_len[left - 1] != INT_MAX / 2) {
                    result = min(result, len + min_len[left - 1]);
                }
                min_so_far = min(min_so_far, len);
            }

            min_len[right] = min_so_far;
        }

        return result >= INT_MAX / 2 ? -1 : result;
    }
};