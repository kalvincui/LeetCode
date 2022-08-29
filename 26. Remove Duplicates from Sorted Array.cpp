class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        while (index < nums.size()){
            while (index + 1 < nums.size() && nums[index] == nums[index+1]){
                nums.erase(nums.begin()+ index+1);
            }
            index++;
        }
        return nums.size();
    }
};


//Alternative solution that is much faster and does not requrie deletion of any elements:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicates = 0;
        for (int i = 1; i<nums.size(); i++){
            if (nums[i] == nums[i-1]){
                duplicates++;
            }else {
                nums[i-duplicates] = nums[i];
            }
        }
        return nums.size() - duplicates;
    }
};
