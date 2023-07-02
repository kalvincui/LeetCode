class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //Number of provinces is the number of unique graphs (graphs that are not connected to eachother)
        //Idea: Do DFS explore all nodes from a starting node, marking all accessible nodes as visited. If you encounter an unvisited node, that means it must be from another graph. Repeat process on that node.
        int ans;
        vector <bool> visited(isConnected.size(), false);
        for (int i = 0; i<isConnected.size(); i++){
            if (!visited[i]){
                visited[i] = true;
                dfs (isConnected, visited, i);
                ans++;
            }
        }
        return ans;
    }
    void dfs (vector<vector<int>>& isConnected, vector<bool>& visited, int idx){
        for (int i = 0; i<isConnected[idx].size(); i++){
            if (!visited[i] && isConnected[idx][i]){
                visited[i] = true;
                dfs(isConnected, visited, i);
            }
        }
    }
};
