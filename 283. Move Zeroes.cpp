class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        while (idx < nums.size()){
            if (nums[idx] == 0){
                int tempidx = idx + 1;
                while (tempidx < nums.size()){
                    if (nums[tempidx] != 0){
                        int temp = nums[tempidx];
                        nums[tempidx] = nums[idx];
                        nums[idx] = temp;
                        break;
                    }
                    tempidx++;
                }
            }
            idx++;
        }
    }
};

//Alternative solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
