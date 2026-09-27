class Solution {
public:
    std::string reverseParentheses(std::string s) {
        int n = s.length();
        std::stack<int> opened;
        std::vector<int> pair(n);

        // First pass: Find matching pairs of parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                opened.push(i);
            } else if (s[i] == ')') {
                int j = opened.top();
                opened.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        // Second pass: Build the result string
        std::string result;
        int direction = 1; 
        
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];       
                direction = -direction; 
            } else {
                result += s[i];
            }
        }

        return result;
    }
};
