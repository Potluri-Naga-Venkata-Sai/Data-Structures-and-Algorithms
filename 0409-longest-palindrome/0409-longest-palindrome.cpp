class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char ch: s){
            mp[ch]++;
        }
        int len = 0;
        bool hasodd = false;
        for(auto it: mp){
            int cnt = it.second;
            len += (cnt / 2) * 2;
            if(cnt % 2 == 1){
                hasodd = true;
            }

        }
        if(hasodd){
            len++;
        }

        return len;
    }
};