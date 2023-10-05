class Solution {
public:
    int jump(vector<int>& nums) {
        vector <int> dp (nums.size()+1, nums.size()-1);
        dp[0] = 0;
        for (int j = 0; j<=nums[0] && j<nums.size(); j++){
            dp[j] = min(dp[0]+1, j);
        }
        for (int i = 1; i<nums.size(); i++){
            for (int j = 0; j<=nums[i] && i+j<nums.size(); j++){
                dp[i+j] = min (dp[i] + 1, dp[i+j]);
            }
        }
        return dp[nums.size()-1];
    }
};
