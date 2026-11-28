class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxIndex[9];

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char ch = board[i][j];
                if(ch == '.'){
                    continue;
                }
                int boxindex = (i / 3) * 3 + (j / 3);
                if(rows[i].count(ch) || cols[j].count(ch) || boxIndex[boxindex].count(ch)){
                    return false;
                }
                rows[i].insert(ch);
                cols[j].insert(ch);
                boxIndex[boxindex].insert(ch);
            }
        }
        return true;
    }
};