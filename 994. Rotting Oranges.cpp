class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //Need a queue with pairs (row, col)
        //Add all rotten orange (row, col) into the queue
        //Add all non-adjacent rotten oranges to queue
        //Change them to rotten
        //Check at end if there are any non rotten oranges, if so return -1
        //Else, return minutes
        queue <pair<int, int>> q;
        for (int i = 0; i<grid.size(); i++){
            for (int j = 0; j<grid[i].size(); j++){
                if (grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int minutes = 0;
        while (!q.empty()){
            int len = q.size();
            bool nonrotten = false;
            for (int i = 0; i<len; i++){
                pair <int, int> coord = q.front();
                q.pop();
                int row = coord.first;
                int col = coord.second;
                if (row-1 >= 0 && grid[row-1][col] == 1){
                    q.push({row-1, col});
                    grid[row-1][col] = 2;
                    nonrotten = true;
                }
                if (row+1 < grid.size() && grid[row+1][col] == 1){
                    q.push({row+1, col});
                    grid[row+1][col] = 2;
                    nonrotten = true;
                }
                if (col-1 >= 0 && grid[row][col-1] == 1){
                    q.push({row, col-1});
                    grid[row][col-1] = 2;
                    nonrotten = true;
                }
                if (col+1 < grid[row].size() && grid[row][col+1] == 1){
                    q.push({row, col+1});
                    grid[row][col+1] = 2;
                    nonrotten = true;
                }
            }
            if (nonrotten){
                minutes++;
            }
        }
        for (int i = 0; i<grid.size(); i++){
            for (int j = 0; j<grid[i].size(); j++){
                if (grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return minutes;
    }
};
