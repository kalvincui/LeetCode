class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector <int> runSum;
        for (int i = 0; i<nums.size(); i++){
            if (i == 0){
                runSum.push_back(nums[i]);
            }else {
                runSum.push_back(runSum[i-1] + nums[i]);
            }
        }
        return runSum;
    }
};
