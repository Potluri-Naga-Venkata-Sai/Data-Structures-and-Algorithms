class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalxor = 0;
        bool zero = true;
        for(int x: nums){
            totalxor ^= x;
            if(x > 0){
                zero = false;
            }
        }
        if(totalxor > 0){
            return n;
        }
        return zero ? 0 : n - 1;
        
    }
};