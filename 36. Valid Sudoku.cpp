class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i<board.size(); i++){
            set <int> row;
            set <int> col;
            for (int j = 0; j<board[i].size(); j++){
                if (board[i][j] != '.'){
                    auto rowitr = row.find(board[i][j]);
                    if (rowitr == row.end()){
                        row.insert(board[i][j]);
                    }else {
                        return false;
                    }
                }
                if (board[j][i] != '.'){
                    auto colitr = col.find(board[j][i]);
                    if (colitr == col.end()){
                        col.insert(board[j][i]);
                    }else {
                        return false;
                    }
                }
            }
        }
        int row = 0, col = 0;
        while (true){
            set <int> box;
            if (row > 6 && col == 6){
                break;
            }
            if (row > 6){
                row = 0;
                col+=3;
            }
            for (int i = row; i<row+3; i++){
                for (int j = col; j<col+3; j++){
                    if (board[i][j] != '.'){
                        auto boxitr = box.find(board[i][j]);
                        if (boxitr == box.end()){
                            box.insert(board[i][j]);
                        }else {
                            return false;
                        }
                    }
                }
            }
            row+=3;
        }
        return true;
    }
};
