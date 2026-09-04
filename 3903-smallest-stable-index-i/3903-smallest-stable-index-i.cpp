class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
     int n = nums.size();

     for(int i = 0; i < n; i++){
        int min_ele = nums[i], max_ele = nums[i];
        for(int j = 0; j < i; j++){
            max_ele = max(max_ele, nums[j]);
        }
        for(int k = i + 1; k < n; k++){
            min_ele = min(min_ele, nums[k]);
        }
        long long ans = (long long)max_ele - min_ele;
        if(ans <= k){
            return i;
        }
     }
     return -1;
    }  
};