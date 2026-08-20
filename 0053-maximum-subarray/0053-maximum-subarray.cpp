class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int max_subarr_sum = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            max_subarr_sum = max(max_subarr_sum, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return max_subarr_sum;
    }
};