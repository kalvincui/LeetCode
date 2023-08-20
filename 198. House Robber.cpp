class Solution {
public:
    int rob(vector<int>& nums) {
        //Can start at any house
        //Can go to any house that is not adjacent to the current house
        //Need to maximize the amount of money
        //House 0 and House 1 max will be amount at that house
        //House 2 max will be amount at House 0 and House 2
        //However, House 3 max will be House 3 + Max(House0, House1)
        //Similary, House 4 max will be House 4 + Max (House0, House1, House2)
        //However, House 2  = House 0 + House 2
        //So House 4 max will be House 4 + Max (House 1, House 2)
        //Max House(n) = House n + Max (House n-2, House n-3)
        //Can either end at House(nums.size()-1) or House (nums.size()-2)
        //Return Max (House(nums.size()-1), House(nums.size()-2))
        if (nums.size()==1){
            return nums[0];
        }
        if (nums.size()==2){
            return max(nums[0], nums[1]);
        }
        nums[2] += nums[0];
        for (int i = 3; i<nums.size(); i++){
            nums[i] += max(nums[i-2], nums[i-3]);
        }
        return max(nums[nums.size()-1], nums[nums.size()-2]);
    }
};
