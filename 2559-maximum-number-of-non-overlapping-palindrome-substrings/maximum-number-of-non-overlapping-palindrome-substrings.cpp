class Solution {
private:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

public:
    int maxPalindromes(string s, int k) {
        int count = 0;
        int n = s.length();
        int i = 0;

        while (i <= n - k) {
            // Check for palindrome of length k
            if (isPalindrome(s, i, i + k - 1)) {
                count++;
                i += k; // Jump past this palindrome
            } 
            // Check for palindrome of length k + 1
            else if (i + k < n && isPalindrome(s, i, i + k)) {
                count++;
                i += k + 1; // Jump past this palindrome
            } 
            else {
                i++;
            }
        }

        return count;
    }
};