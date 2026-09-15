#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(string &s, int start, int end) {
        int size = end - start + 1;
        int mid = size / 2;
        int last = end;

        for (int i = start; i < start + mid; i++) {
            char ch = s[i];

            if (ch != s[last]) {
                return false;
            }

            last--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();

        // palindrome[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        // Precompute palindromes
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (len == 1) {
                    palindrome[i][j] = true;
                }
                else if (len == 2) {
                    palindrome[i][j] = (s[i] == s[j]);
                }
                else {
                    palindrome[i][j] =
                        (s[i] == s[j] && palindrome[i + 1][j - 1]);
                }
            }
        }

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            dp[i] = dp[i - 1];

            for (int j = 0; j <= i - k; j++) {

                if (palindrome[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};
