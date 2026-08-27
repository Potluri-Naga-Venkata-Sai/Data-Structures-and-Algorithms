class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate nums[i]
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            unordered_set<int> hash_set;

            for (int j = i + 1; j < n; j++) {

                int third = -(nums[i] + nums[j]);

                if (hash_set.find(third) != hash_set.end()) {

                    ans.push_back({
                        nums[i],
                        third,
                        nums[j]
                    });

                    // Skip duplicate nums[j]
                    while (j + 1 < n && nums[j] == nums[j + 1])
                        j++;
                }

                hash_set.insert(nums[j]);
            }
        }

        return ans;
    }
};