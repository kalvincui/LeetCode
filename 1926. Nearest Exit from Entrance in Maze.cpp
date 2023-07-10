class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //BFS, so use a QUEUE
        //May need a visited vector, to ensure you don't visit a square you already went to
        //If the path is valid and is not visited, increment steps by 1, and add that {row, col} into the queue
        //Becuase you need row and col, probably need a queue of pairs
        //Need to check row +/- 1, and col +/- 1
        //If square = exit, return the steps
        int steps = 0;
        vector<vector<bool>> visited (maze.size(), vector<bool>(maze[0].size(), false));
        queue <pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        while (!q.empty()){
            int len = q.size();
            for (int i = 0; i<len; i++){
                pair<int, int> point = q.front();
                q.pop();
                int row = point.first;
                int col = point.second;
                if (!visited[row][col]){
                    if ((row == maze.size()-1 || row==0 || col == maze[row].size()-1 || col == 0) && steps!=0){
                        return steps;
                    }
                    visited[row][col] = true;
                    if (row-1 >= 0 && maze[row-1][col] == '.'){
                        q.push({row-1, col});
                    }
                    if (row+1 < maze.size() && maze[row+1][col] == '.'){
                        q.push({row+1, col});
                    }
                    if (col-1 >= 0 && maze[row][col-1] == '.'){
                        q.push({row, col-1});
                    }
                    if (col+1 < maze[row].size() && maze[row][col+1] == '.'){
                        q.push({row, col+1});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
