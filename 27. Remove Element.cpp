class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        while (index < nums.size()){
            while (nums[index] == val && index < nums.size()){
                nums.erase (nums.begin() + index);
            }
            index++;
        }
        return nums.size();
    }
};
