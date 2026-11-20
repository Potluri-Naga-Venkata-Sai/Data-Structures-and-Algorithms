
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        // If sum is odd, equal partition is impossible
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;

        // dp[j] tells whether sum j is possible
        vector<bool> dp(target + 1, false);

        // Sum 0 is always possible
        dp[0] = true;

        for (int num : nums) {

            // Traverse backwards
            for (int j = target; j >= num; j--) {

                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};
