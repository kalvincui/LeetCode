class Solution {
public:
    string convert(string s, int numRows) {
        int row = 0;
        int col = 0;
        string output = "";
        int cur = 0;
        bool zig = false;
        char grid [numRows][s.size()];
        if (numRows == 1){
            return s;
        }else {
            for (int i = 0; i<numRows; i++){
                for (int j = 0; j<s.size(); j++){
                    grid[i][j] = ' ';
                }
            }
            while (cur < s.size()){
                grid[row][col] = s[cur];
                if ((row+1) == numRows){
                    zig = true;
                }
                if (row == 0){
                    zig = false;
                }
                if (zig){
                    row --;
                    col++;
                }else {
                    row ++;
                }
                cur++;
            }
            for (int i = 0; i<numRows; i++){
                for (int j = 0; j<s.size(); j++){
                    if (!isspace(grid[i][j])){
                        output += grid[i][j];
                    }   
                }
            }
            return output;
        }
    }
};
