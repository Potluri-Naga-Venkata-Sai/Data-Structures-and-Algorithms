class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total_sum = 0;
        for(int x: nums){
            total_sum += x;
        }
        int target = total_sum - x;
        if(target < 0){
            return -1;
        }
        if(target == 0){
            return n;
        }
        int left = 0;
        int sum = 0;
        int max_len = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            while(sum > target){
                sum -= nums[left];
                left++;
            }
            if(sum == target){
                max_len = max(max_len, i - left + 1);
            }
        }
        if(max_len == INT_MIN){
            return -1;
        }
        return n - max_len;
    }
};