class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //Row 1: 1
        //Row 2: 1 1
        //Row 3: 1 2 1
        //Row 4: 1 3 3 1
        //Row 5: 1 4 6 4 1
        //First and Last Numbers of Each Row = 1
        //Numbers in between = Sum of Number Directly Above to the Left and Number Directly Above
        //Idea: Nested for loop, with first 2 rows already pushed into a 2D vector
        //Push rows into the vector as you go
        //First and Last Entries are Zero, so you don't start at 0 index
        //Time complexity shouldn't matter too much, as numRows <= 30
        vector<vector<int>> ans;
        for (int i = 0; i<numRows; i++){
            vector <int> rowval;
            if (i == 0){
                rowval.push_back(1);
                //ans.push_back(rowval);
            }else if (i==1){
                rowval.push_back(1);
                rowval.push_back(1);
                //ans.push_back(rowval);
            }else {
                rowval.push_back(1);
                for (int j = 1; j<i; j++){
                    rowval.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
                rowval.push_back(1);
            }
            ans.push_back(rowval);
        }
        return ans;
    }
};
