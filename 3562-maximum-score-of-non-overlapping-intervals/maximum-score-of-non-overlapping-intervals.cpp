using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<tuple<int, int, int, int>> sorted_intervals(n);
        for (int i = 0; i < n; ++i) {
            sorted_intervals[i] = {intervals[i][1], intervals[i][0], intervals[i][2], i};
        }
        
        sort(sorted_intervals.begin(), sorted_intervals.end());
        
        vector<int> R(n);
        for (int i = 0; i < n; ++i) {
            R[i] = get<0>(sorted_intervals[i]);
        }
        
        vector<int> p(n, -1);
        for (int i = 0; i < n; ++i) {
            int l = get<1>(sorted_intervals[i]);
            auto it = lower_bound(R.begin(), R.end(), l);
            int idx = distance(R.begin(), it) - 1;
            p[i] = idx;
        }
        
        using State = pair<long long, vector<int>>;
        
        auto is_better = [](const State& a, const State& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        };

        vector<vector<State>> dp(5, vector<State>(n + 1, {0LL, {}}));
        
        for (int k = 1; k <= 4; ++k) {
            for (int i = 1; i <= n; ++i) {
                State best = dp[k][i - 1];
                
                int prev_idx = p[i - 1];
                long long w = get<2>(sorted_intervals[i - 1]);
                int orig_idx = get<3>(sorted_intervals[i - 1]);
                
                State take = dp[k - 1][prev_idx + 1];
                take.first += w;
                take.second.push_back(orig_idx);
                sort(take.second.begin(), take.second.end());
                
                if (is_better(take, best)) {
                    best = take;
                }
                
                dp[k][i] = best;
            }
        }
        
        return dp[4][n].second;
    }
};