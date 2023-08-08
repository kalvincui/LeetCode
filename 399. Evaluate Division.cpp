class Solution {
public:
    unordered_map <string, vector<pair<string, double>>> graph;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //Create an adjacency list for every string
        //In the list should contain the string it can go to + cost (pair)
        //Since no zero division, you can have both forward and backward traversal
        //Go through all the queries, performing DFS starting from the first trying to go to second
        set <string> check;
        vector <double> ans;
        for (int i = 0; i<equations.size(); i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            check.insert(equations[i][0]);
            check.insert(equations[i][1]);
        }
        for (auto q : queries){
            set <string> visited;
            if (check.count(q[0]) == 0 || check.count(q[1]) == 0){
                ans.push_back(-1);
            }else {
                visited.insert(q[0]);
                ans.push_back(dfs(q[0], q[1], visited));
            }
        }
        return ans;
    }
    double dfs (string start, string target, set <string>& visited){
        if (start == target){
            return 1;
        }
        for (auto node : graph[start]){
            if (visited.count(node.first) == 0){
                visited.insert(node.first);
                double res = dfs(node.first, target, visited);
                if (res != -1){
                    return res * node.second;
                }
            }
        }
        return -1;
    }
};
