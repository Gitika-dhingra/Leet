class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> l(26, -1), r(26, -1);
        
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            if (l[ch] == -1) l[ch] = i;
            r[ch] = i;
        }

        auto checkSubstring = [&](int i) -> int {
            int right = r[s[i] - 'a'];
            for (int j = i; j <= right; ++j) {
                if (l[s[j] - 'a'] < i) return -1;
                right = max(right, r[s[j] - 'a']);
            }
            return right;
        };

        vector<pair<int, int>> validSubstrings;
        for (int i = 0; i < n; ++i) {
            if (i == l[s[i] - 'a']) {
                int right = checkSubstring(i);
                if (right != -1) {
                    validSubstrings.push_back({right, i});
                }
            }
        }

        sort(validSubstrings.begin(), validSubstrings.end());

        vector<string> result;
        int lastEnd = -1;
        for (auto& p : validSubstrings) {
            int right = p.first;
            int left = p.second;
            if (left > lastEnd) {
                result.push_back(s.substr(left, right - left + 1));
                lastEnd = right;
            }
        }

        return result;
    }
};