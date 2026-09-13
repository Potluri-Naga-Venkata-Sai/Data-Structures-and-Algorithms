class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n1 = img1.size();
        int m1 = img1[0].size();

        vector<pair<int, int>> indeces_1;
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < m1; j++){
                if(img1[i][j] == 1){
                    indeces_1.push_back({i, j});
                }
            }
        }

        int n2 = img2.size();
        int m2 = img2[0].size();

        vector<pair<int, int>> indeces_2;
        for(int i = 0; i < n2; i++){
            for(int j = 0; j < m2; j++){
                if(img2[i][j] == 1){
                    indeces_2.push_back({i, j});
                }
            }
        }
        int ans = 0;
        map<pair<int, int>, int> mp;
        for(auto& it_1: indeces_1){
            for(auto& it_2: indeces_2){
                int dr = it_2.first - it_1.first;
                int dc = it_2.second - it_1.second;

                mp[{dr, dc}]++;

                ans = max(ans, mp[{dr, dc}]);
            }
        }
        return ans;
    }
};