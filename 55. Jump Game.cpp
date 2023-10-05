//TLE
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector <bool> dp (nums.size(), false);
        dp[0] = true;
        for (int i = 0; i<nums.size()-1; i++){
            if (!dp[i]){
                continue;
            }
            for (int j = 0; j<=nums[i] && j+i < nums.size(); j++){
                dp[i+j] = true;
            }
        }
        return dp[nums.size()-1];
    }
};
