class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int cnt = 0;
        int found = 0;
        int length = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = i; j < n; j++){
                if(s[j] == '1'){
                    cnt++;
                    if(cnt == k){
                        string curr = s.substr(i, j - i + 1);
                        if((curr.size() == ans.size() && curr < ans) || ans.empty() || curr.size() < ans.size()){
                            ans = curr;
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};