class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        int left = 0;
        int sum = 0;
        int ans = INF;
        vector<int> best(n, 1e9);
        for(int i = 0; i < n; i++){
            sum += arr[i];
            while(sum > target){
                sum -= arr[left];
                left++;
            }
            if(sum == target){
                int len = i - left + 1;
                if(left > 0 && best[left - 1] != 1e9){
                    ans = min(ans, len + best[left - 1]);
                }
                if(i == 0){
                    best[i] = len;
                }else{
                    best[i] = min(best[i - 1], len);
                }
            }else{
                if(i > 0){
                    best[i] = best[i - 1];
                }
            }

        }
        return ans == INF ? -1 : ans;
    }
};