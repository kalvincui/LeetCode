//Iterative Solution
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector <bool> visited (rooms.size(), false);
        stack <int> s;
        s.push(0);
        while (!s.empty()){
            int roomidx = s.top();
            s.pop();
            if (!visited[roomidx]){
                visited[roomidx] = true;
                for (int i = 0; i<rooms[roomidx].size(); i++){
                    s.push(rooms[roomidx][i]);
                }
            }
        }
        for (int i = 0; i<visited.size(); i++){
            if (!visited[i]){
                return false;
            }
        }
        return true;
    }
};
