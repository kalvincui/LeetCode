class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsubarray = nums[0];
        vector <int> dp (nums.size()+1, 0);
        dp[0] = nums[0];
        for (int i = 1; i<nums.size(); i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            maxsubarray = max(maxsubarray, dp[i]);
        }
        return maxsubarray;
    }
};
