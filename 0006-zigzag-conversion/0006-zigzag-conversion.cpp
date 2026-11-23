class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        int curr_row = 0;
        int dir = 1;
        if(numRows >= s.size() || numRows == 1){
            return s;
        }
        for(char c: s){
            rows[curr_row] += c;
            if(curr_row == 0){
                dir = 1;
            }else if(curr_row == numRows - 1){
                dir = -1;
            }
            curr_row += dir;
        }
        string ans = "";
        for(string row: rows){
            ans += row;
        }
        return ans;
    }
};