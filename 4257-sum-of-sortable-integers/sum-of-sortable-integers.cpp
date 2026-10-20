
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        vector<int> divisors;
        for (int k = 1; k * k <= n; k++) {
            if (n % k == 0) {
                divisors.push_back(k);
                if (k != n / k)
                    divisors.push_back(n / k);
            }
        }

        int ans = 0;

        for (int k : divisors) {
            bool ok = true;

            for (int i = 0; i < n; i += k) {
                int drops = 0;
                int mn = INT_MAX, mx = INT_MIN;

                for (int j = i; j < i + k; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);

                    if (j > i && nums[j] < nums[j - 1])
                        drops++;
                }

                if (drops > 1 ||
                    (drops == 1 && nums[i] < nums[i + k - 1]) ||
                    mn != sorted[i] ||
                    mx != sorted[i + k - 1]) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans += k;
        }

        return ans;
    }
};
