class Solution {
public:
    int changes = 0;
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> map (n);
        vector<bool> visited(n, false);
        for (int i = 0; i<connections.size(); i++){
            map[connections[i][0]].push_back(connections[i][1]);
            map[connections[i][1]].push_back(-connections[i][0]);
        }
        dfs (map, visited, 0);
        return changes;
    }
    void dfs (vector<vector<int>>& map, vector<bool>& visited, int idx){
        visited[idx] = true;
        for (int i = 0; i<map[idx].size(); i++){
            //cout << map[idx][i] << '\n';
            if (map[idx][i] > 0 && !visited[abs(map[idx][i])]){
                changes++;
            }
            if (!visited[abs(map[idx][i])]){
                dfs(map, visited, abs(map[idx][i]));
            }
        }
    }
};

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        //Idea: Create a map between all nodes?
        //If the node is connected to another node, label it as 1, and since it is one way, label the other node as -1
        //Traverse across the entire map, starting from the 0 node, if the connection is 1, no need to replace, if the connection is -1 need to
        //replace
        //Minimum edges changes is the number of -1 flipped to 1
        //Create 2D map nxn

        //Works but TLE
        vector<vector<int>> map (n, vector<int>(n, 0));
        vector<bool> visited (n, false);
        for (int i = 0; i<connections.size(); i++){
            map[connections[i][0]][connections[i][1]] = 1;
            map[connections[i][1]][connections[i][0]] = -1;
        }
        int changes = 0;
        queue <int> col;
        for (int i = 0; i<n; i++){
            int num = map[i][0];
            if (num!=0){
                col.push(i);
                map[i][0] = 1;
                map[0][i] = 1;
            }
            if (num == -1){
                changes++;
            }
            visited[0] = true;
        }
        while (!col.empty()){
            int colnum = col.front();
            col.pop();
            if (!visited[colnum]){
                visited[colnum] = true;
                for (int i = 0; i<n; i++){
                int num = map[i][colnum];
                    if (num!= 0 && !visited[i]){
                        col.push(i);
                        map[i][colnum] = 1;
                        map[colnum][i] = 1;
                    }
                    if (num == -1){
                        changes++;
                    }
                }
            }
        }
        return changes;
    }
};
