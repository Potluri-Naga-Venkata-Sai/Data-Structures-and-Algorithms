class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int min_index = 0;

        int max_index = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] < nums[min_index]){
                min_index = i;
            }
            if(nums[i] > nums[max_index]){
                max_index = i;
            }
        }

        int first = max(min_index, max_index) + 1;
        int last = max(n - min_index, n - max_index);
        int first_last = (min_index + 1) + (n - max_index);
        int last_first = (max_index + 1) + (n - min_index);
        int ans = min({first, last, first_last, last_first});
        return ans;
    }
};