class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int num: nums){
            mp[num]++;
        }
        for(auto& num: mp){
            if(num.second > n / 2){
                return num.first;
            }
        }
        return 0;
    }
};