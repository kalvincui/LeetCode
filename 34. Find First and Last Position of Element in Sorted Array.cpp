class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;
        int tempindex = 0;
        while (tempindex < nums.size() && nums[tempindex] <= target){
            if (nums[tempindex] == target){
                start = tempindex;
                break;
            }
            tempindex++;
        }
        tempindex = nums.size()-1;
        while (tempindex >= 0 && nums[tempindex] >= target){
            if (nums[tempindex] == target){
                end = tempindex;
                break;
            }
            tempindex--;
        }
        return {start, end};
    }
};
