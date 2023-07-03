class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //If it is 1, traverse all possible ones, mark as visited
        //If not 1, mark as visited
        vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for (int i = 0; i<grid.size(); i++){
            for (int j = 0; j<grid[i].size(); j++){
                if (!visited[i][j] && grid[i][j] =='1'){
                    visited[i][j] = true;
                    dfs (grid, visited, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs (vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col){
        if (col-1 >= 0 && !visited[row][col-1] && grid[row][col-1] == '1'){
            visited[row][col-1] = true;
            dfs (grid, visited, row, col-1);
        }
        if (col+1 <grid[row].size() && !visited[row][col+1] && grid[row][col+1] == '1'){
            visited[row][col+1] = true;
            dfs (grid, visited, row, col+1);
        }
        if (row-1 >= 0 && !visited[row-1][col] && grid[row-1][col] == '1'){
            visited[row-1][col] = true;
            dfs (grid, visited, row-1, col);
        }
        if (row+1 <grid.size() && !visited[row+1][col] && grid[row+1][col] == '1'){
            visited[row+1][col] = true;
            dfs (grid, visited, row+1, col);
        }
    }
};
