class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<long long>> table;

    long long dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long left_ways = dfs(left);
        long long right_ways = dfs(right);

        int L = left.size();
        int R = right.size();

        // Ways to merge left and right subtrees: C(L + R, L) * left_ways * right_ways
        long long ways = (table[L + R][L] * left_ways) % MOD;
        ways = (ways * right_ways) % MOD;

        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        // Precompute Pascal's triangle for combinations C(n, k)
        table.resize(n + 1, vector<long long>(n + 1, 1));
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }

        return (dfs(nums) - 1 + MOD) % MOD;
    }
};