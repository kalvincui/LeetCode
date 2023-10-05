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
