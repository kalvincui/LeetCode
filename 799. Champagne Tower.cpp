//TLE
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        return amount(poured, query_row, query_glass);
    }
    double amount (int poured, int row, int glass){
        if (row ==0 && glass == 0){
            return poured;
        }
        if (glass > row || glass <0 || row < 0){
            return 0;
        }
        double left = (amount(poured, row-1, glass-1)-1)/2;
        double right = (amount(poured, row-1, glass)-1)/2;
        if (left < 0){
            left = 0;
        }
        if (right < 0){
            right = 0;
        }
        return left + right;
    }
};

//DP
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp (query_row+1, vector<double>(query_row+1, 0));
        dp[0][0] = poured;
        for(int row = 0; row < query_row; row++){
            for(int col = max(0, query_glass - query_row + row); col <= row && col <= query_glass; col++){
                if(dp[row][col] > 1){
                    dp[row+1][col] += (dp[row][col]-1)/2;
                    dp[row+1][col+1] += (dp[row][col]-1)/2;
                }
            }
        }
        return min(dp[query_row][query_glass], 1.0);
    }
};
