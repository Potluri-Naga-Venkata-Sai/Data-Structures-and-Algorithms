class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> ans(n);

        vector<pair<int, int>> groups;
        for(int i = 0; i < n; i++){
            groups.push_back({nums[i], i});
        }
        sort(groups.begin(), groups.end());

        int start = 0;
        while(start < n){
            int end = start;
            while(end + 1 < n && groups[end + 1].first - groups[end].first <= limit){
                end++;
            }

            vector<int> indeces;
            for(int i = start; i <= end; i++){
                indeces.push_back(groups[i].second);
            }
            sort(indeces.begin(), indeces.end());

            for(int i = start; i <= end; i++){
                ans[indeces[i - start]] = groups[i].first;
            }
            start = end + 1;
        }
        return ans;
    }
};