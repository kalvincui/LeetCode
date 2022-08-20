class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort (nums.begin(), nums.end());
        int ans = -1000000;
        for (int i = 0; i<nums.size(); i++){
            int start = i+1;
            int end = nums.size()-1;
            while (start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if (abs(target - sum) < abs(target-ans)){
                    ans = sum;
                }
                if (sum > target){
                    end--;
                }else if (sum < target){
                    start++;
                }else if (sum == target){
                    return target;
                }
            }
        }
        return ans;
    }
};
