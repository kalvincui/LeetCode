class Solution {
public:
    unordered_map<int, int> dp;
    int integerBreak(int n) {
        dp[1] = 1;
        return dfs(n, n);
    }
    int dfs(int n, int num){
        if (dp[num]){
            return dp[num];
        }
        if (num == n){
            dp[num] = 0;
        }else{
            dp[num] = num;
        }
        for (int i = 1; i<num; i++){
            int val = dfs(n, i) * dfs(n, num-i);
            dp[num] = max(dp[num], val);
        }
        return dp[num];
    }
};
