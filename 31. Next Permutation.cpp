class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size()-2;
        bool checker = false;
        while (index >= 0){
            int swapindex = index -1;
            checker = false;
            for (int i = nums.size()-1; i>index; i--){
                if (nums[index] < nums[i]){
                    checker = true;
                    swap (nums[i], nums[index]);
                    sort (nums.begin() + index + 1, nums.end());
                    break;
                }
            }
            if (checker){
                break;
            }
            index--;
        }
        if (!checker){
            sort (nums.begin(), nums.end());
        }
    }
};
