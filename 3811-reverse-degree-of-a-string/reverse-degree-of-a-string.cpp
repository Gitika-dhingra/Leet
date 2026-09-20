class Solution {
public:
    int reverseDegree(string s) {
        int totalSum = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            int reversedAlphabetPos = 'z' - s[i] + 1;
            int stringPos = i + 1;
            totalSum += reversedAlphabetPos * stringPos;
        }
        
        return totalSum;
    }
};