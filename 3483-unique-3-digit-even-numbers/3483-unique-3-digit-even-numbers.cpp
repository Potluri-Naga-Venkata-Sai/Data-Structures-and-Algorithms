class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        map<int, int> mp;
        for(int i: digits){
            mp[i]++;
        }
        int ans = 0;
        for(int i = 1; i <= 9; i++){
            if(mp[i] == 0){
                continue;
            }
            mp[i]--;

            for(int j = 0; j <= 9; j++){
                if(mp[j] == 0){
                    continue;
                }
                mp[j]--;

                for(int k = 0; k <= 8; k += 2){
                    if(mp[k] > 0){
                        ans++;
                    }
                }
                mp[j]++;
            }
            mp[i]++;

        }
        return ans;
    }
};