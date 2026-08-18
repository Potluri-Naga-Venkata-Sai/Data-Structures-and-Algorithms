class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int num: nums){
            mp[num]++;
        }
        if(k == n){
            return *max_element(nums.begin(), nums.end());
        }
        if(k == 1){
            int mx = -1;
            for(int num: nums){
                if(mp[num] == 1){
                    mx = max(mx, num);
                }
            }
            return mx;
        }
        int ans = -1;
        if(mp[nums[0]] == 1){
            ans = max(ans, nums[0]);
        }
        if(mp[nums[n - 1]] == 1){
            ans = max(ans, nums[n - 1]);
        }
        return ans;
    }
};