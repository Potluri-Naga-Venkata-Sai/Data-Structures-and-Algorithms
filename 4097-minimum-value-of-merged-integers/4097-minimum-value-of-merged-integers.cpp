
class Solution {
public:
    long long minMergedInteger(vector<int>& nums) {
        long long ans = LLONG_MAX;

        for (int i = 0; i < nums.size(); i += 2) {
            string merged = to_string(nums[i]) + to_string(nums[i + 1]);

            long long val = stoll(merged);

            ans = min(ans, val);
        }

        return ans;
    }
};
