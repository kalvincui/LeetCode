class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int equal = 0;
        map <int, vector<int>> rows;
        map <int, vector<int>> cols;
        for (int i = 0; i<grid.size(); i++){
            vector <int> currows;
            vector <int> curcols;
            for (int j = 0; j<grid[i].size(); j++){
                currows.push_back(grid[i][j]);
                curcols.push_back(grid[j][i]);
            }
            rows.insert({i, currows});
            cols.insert({i, curcols});
        }
        for (auto rowitr = rows.begin(); rowitr!=rows.end(); rowitr++){
            for (auto colitr = cols.begin(); colitr!=cols.end(); colitr++){
                if (rowitr->second == colitr->second){
                    equal++;
                }
            }
        }
        return equal;
    }
};
