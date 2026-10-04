class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;   // Minimum required open brackets
        int high = 0;  // Maximum possible open brackets

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { // c == '*'
                low--;   // treat as ')'
                high++;  // treat as '('
            }

            // More ')' than possible '(' + '*'
            if (high < 0) return false;

            // low cannot be negative (we can't have negative open brackets)
            if (low < 0) low = 0;
        }

        return low == 0;
    }
};