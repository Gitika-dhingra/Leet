class Solution {
private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return result;

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (isValid(current)) {
                result.push_back(current);
                found = true;
            }

            if (found) continue;

            for (int i = 0; i < current.length(); i++) {
                if (current[i] != '(' && current[i] != ')') continue;

                string nextState = current.substr(0, i) + current.substr(i + 1);

                if (visited.find(nextState) == visited.end()) {
                    visited.insert(nextState);
                    q.push(nextState);
                }
            }
        }

        return result;
    }
};