class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set <int> check;
        for (int i = 0; i<nums.size(); i++){
            int originalsize = check.size();
            check.insert(nums[i]);
            if (originalsize==check.size()){
                return nums[i];
            }
        }
        return -1;
    }
};
