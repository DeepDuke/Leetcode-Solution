/*
Method: check each row, each column, each small box respectively
Time: O(n)
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkEachRow(board) && checkEachColumn(board) && checkSmallBox(board);
    }
private:
    bool checkEachRow(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            vector<int> hash(10, 0);
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] != '.'){
                    hash[board[i][j]-'0']++;
                    if(hash[board[i][j]-'0'] > 1) return false;
                }
            }
        }
        return true;
    }
    bool checkEachColumn(vector<vector<char>>& board){
        for(int j = 0; j < board[0].size(); j++){
            vector<int> hash(10, 0);
            for(int i = 0; i < board.size(); i++){
                if(board[i][j] != '.'){
                    hash[board[i][j]-'0']++;
                    if(hash[board[i][j]-'0'] > 1) return false;
                }
            }
        }
        return true;
    }
    bool checkSmallBox(vector<vector<char>>& board){
        vector<int> X = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        vector<int> Y = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        for(int i = 1; i <= 7; i += 3){
            for(int j = 1; j <= 7; j += 3){
                // for each small  box
                vector<int> hash(10, 0);
                for(int k = 0; k < X.size(); k++){
                    char now =  board[i+X[k]][j+Y[k]];
                    if(now != '.'){
                        hash[now-'0']++;
                        if(hash[now-'0'] > 1) return false;
                    }
                }
                
            }
        }
        return true;
    }
};