class Solution {
public:
    unordered_set<string> ans;

    void dfs(string& s, int index,
             int left_cnt, int right_cnt,
             int left_rem, int right_rem,
             string curr) {

        // Base case
        if (index == s.size()) {
            if (left_rem == 0 &&
                right_rem == 0 &&
                left_cnt == right_cnt) {

                ans.insert(curr);
            }
            return;
        }

        char ch = s[index];

        // '('
        if (ch == '(') {

            // Remove '('
            if (left_rem > 0) {
                dfs(s, index + 1,
                    left_cnt, right_cnt,
                    left_rem - 1, right_rem,
                    curr);
            }

            // Keep '('
            dfs(s, index + 1,
                left_cnt + 1, right_cnt,
                left_rem, right_rem,
                curr + ch);
        }

        // ')'
        else if (ch == ')') {

            // Remove ')'
            if (right_rem > 0) {
                dfs(s, index + 1,
                    left_cnt, right_cnt,
                    left_rem, right_rem - 1,
                    curr);
            }

            // Keep ')' only if there is an unmatched '('
            if (left_cnt > right_cnt) {
                dfs(s, index + 1,
                    left_cnt, right_cnt + 1,
                    left_rem, right_rem,
                    curr + ch);
            }
        }

        // Normal character
        else {
            dfs(s, index + 1,
                left_cnt, right_cnt,
                left_rem, right_rem,
                curr + ch);
        }
    }  // <-- closes dfs()

    vector<string> removeInvalidParentheses(string s) {

        int left_rem = 0;
        int right_rem = 0;

        // Find minimum number of removals
        for (char c : s) {

            if (c == '(') {
                left_rem++;
            }
            else if (c == ')') {

                if (left_rem > 0) {
                    left_rem--;
                }
                else {
                    right_rem++;
                }
            }
        }

        dfs(s, 0, 0, 0,
            left_rem, right_rem, "");

        return vector<string>(ans.begin(), ans.end());
    }
};
