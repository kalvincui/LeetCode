//TLE
class Solution {
public:
    int res = -1;
    int coinChange(vector<int>& coins, int amount) {
        getPossibilites(coins, amount, 0, 0);
        return res;
    }
    void getPossibilites (vector<int>& coins, int amount, long sum, int num){
        if (sum == amount){
            if (res == -1){
                res = num;
            }else {
                res = min(res, num);
            }
        }
        if (sum > amount){
            return;
        }
        for (int i = 0; i<coins.size(); i++){
            getPossibilites(coins, amount, sum+coins[i], num+1);
        }
    }
};


//DP
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount+1, amount+1);
        dp[0] = 0;
        for (int i =1; i<amount+1; i++){
            for (int j = 0; j<coins.size(); j++){
                if (i - coins[j] >= 0){
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }
        if (dp[amount] != amount+1){
            return dp[amount];
        }else {
            return -1;
        }
    }
};

