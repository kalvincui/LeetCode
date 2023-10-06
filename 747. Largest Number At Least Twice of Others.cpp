class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx = -1;
        int largest = -1;
        int secondlargest = -1;
        for (int i = 0; i<nums.size(); i++){
            if (nums[i] > largest){
                idx = i;
                secondlargest = largest;
                largest = nums[i];
            }else if (nums[i] > secondlargest){
                secondlargest = nums[i];
            }
        }
        if (largest >= 2*secondlargest){
            return idx;
        }
        return -1;
    }
};
