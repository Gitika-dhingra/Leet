class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLen = 0;
        int n = s.length();

        // Loop over the target number of unique characters allowed in the sliding window
        for (int targetUnique = 1; targetUnique <= 26; ++targetUnique) {
            vector freq(26, 0);
            int left = 0, right = 0;
            int uniqueCount = 0;
            int countAtLeastK = 0;

            while (right < n) {
                // Expand window
                if (uniqueCount <= targetUnique) {
                    int idx = s[right] - 'a';
                    if (freq[idx] == 0) uniqueCount++;
                    freq[idx]++;
                    if (freq[idx] == k) countAtLeastK++;
                    right++;
                } 
                // Shrink window
                else {
                    int idx = s[left] - 'a';
                    if (freq[idx] == k) countAtLeastK--;
                    freq[idx]--;
                    if (freq[idx] == 0) uniqueCount--;
                    left++;
                }

                // Update max length if window satisfies conditions
                if (uniqueCount == targetUnique && uniqueCount == countAtLeastK) {
                    maxLen = max(maxLen, right - left);
                }
            }
        }

        return maxLen;
    }
};