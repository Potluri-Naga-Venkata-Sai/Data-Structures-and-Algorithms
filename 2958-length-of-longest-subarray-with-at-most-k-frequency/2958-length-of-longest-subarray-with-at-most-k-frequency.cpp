class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int start = -1;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            while(mp[nums[i]] > k){
                start++;
                mp[nums[start]]--;
            }
            ans = max(ans, i - start);
        }
        return ans;
    }
};