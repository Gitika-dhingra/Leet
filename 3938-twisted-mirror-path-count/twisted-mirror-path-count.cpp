#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;

        // Helper function to resolve the landing cell given a start position and initial direction
        // dir: 0 for trying to move Right, 1 for trying to move Down
        auto get_next = [&](int r, int c, int dir) -> pair<int, int> {
            while (true) {
                if (dir == 0) { // trying to move right
                    c++;
                } else { // trying to move down
                    r++;
                }

                // Check out of bounds
                if (r < 0 || r >= m || c < 0 || c >= n) {
                    return {-1, -1};
                }

                // If it's a mirror, it reflects
                if (grid[r][c] == 1) {
                    if (dir == 0) {
                        dir = 1; // Right reflection turns Down
                    } else {
                        dir = 0; // Down reflection turns Right
                    }
                } else {
                    // Reached an empty cell
                    return {r, c};
                }
            }
        };

        // Precompute jump targets for all cells and both directions
        // jump[i][j][0] -> landing spot when trying to move Right from (i, j)
        // jump[i][j][1] -> landing spot when trying to move Down from (i, j)
        vector<vector<vector<pair<int, int>>>> jump(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2)));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                jump[i][j][0] = get_next(i, j, 0);
                jump[i][j][1] = get_next(i, j, 1);
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                // Try moving Right
                auto [nr, nc] = jump[i][j][0];
                if (nr != -1 && nc != -1) {
                    dp[nr][nc] = (dp[nr][nc] + dp[i][j]) % MOD;
                }

                // Try moving Down
                auto [dr, dc] = jump[i][j][1];
                if (dr != -1 && dc != -1) {
                    dp[dr][dc] = (dp[dr][dc] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};