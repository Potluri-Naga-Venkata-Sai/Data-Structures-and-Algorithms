class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int m = num % k;

            vector<long long> newDp(k, 0);

            newDp[m]++;
            for (int r = 0; r < k; r++) {
                int newRemainder = (r * m) % k;
                newDp[newRemainder] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};
