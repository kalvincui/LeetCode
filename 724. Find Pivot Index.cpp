class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivotindex = 0;
        if (nums.size() == 0){
            return -1;
        }
        while (pivotindex < nums.size()){
            int leftsum = 0;
            int rightsum = 0;
            for (int i = 0; i<pivotindex; i++){
                leftsum += nums[i];
            }
            for (int i = pivotindex+1; i<nums.size(); i++){
                rightsum += nums[i];
            }
            if (leftsum == rightsum){
                return pivotindex;
            }
            pivotindex ++;
        }
        return -1;       
    }
};
