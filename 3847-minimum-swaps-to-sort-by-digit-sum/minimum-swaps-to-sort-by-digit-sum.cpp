class Solution {
private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Store pairs of (number, original_index)
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        
        // Sort based on digit sum, then by value
        sort(arr.begin(), arr.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            int sumA = getDigitSum(a.first);
            int sumB = getDigitSum(b.first);
            if (sumA != sumB) {
                return sumA < sumB;
            }
            return a.first < b.first;
        });
        
        // Find minimum swaps using cycle detection
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            // If already visited or already in the correct position
            if (visited[i] || arr[i].second == i) {
                continue;
            }
            
            // Traverse the cycle
            int cycle_size = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].second;
                cycle_size++;
            }
            
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};