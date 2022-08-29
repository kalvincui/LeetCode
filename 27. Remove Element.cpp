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
//Alternative solution that does not require the deletion of any element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i<nums.size(); i++){
            if (nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
