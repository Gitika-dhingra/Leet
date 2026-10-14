#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
        // If the total sum required is greater than the maximum possible sum 
        // with 'num' digits (9 * num), or if the sum is negative, it's impossible.
        if ((long long)num * 9 < sum || sum < 0) {
            return "";
        }

        std::string ans = "";
        ans.reserve(num);

        for (int i = 0; i < num; ++i) {
            int digit = std::min(9, sum);
            ans.push_back('0' + digit);
            sum -= digit;
        }

        // If any sum is left over after filling 'num' digits, it's invalid.
        if (sum > 0) {
            return "";
        }

        return ans;
    }
};