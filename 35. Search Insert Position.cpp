class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        while (index < nums.size() && target > nums[index]){
            index++;
        }
        return index;
    }
};
