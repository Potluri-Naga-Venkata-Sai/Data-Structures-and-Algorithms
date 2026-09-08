class Solution {
public:
    int countCommas(int n) {
        string str = to_string(n);
        int size = str.length();
        if(size < 3){
            return 0;
        }
        int cnt = 0;
        while(n >= 1000){
            cnt++;
            n--;
        }
        return cnt;
    }
};