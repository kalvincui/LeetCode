//Not constant extra space
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


//Constant Extra Space Solution
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size()>1){
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow!=fast){
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            fast = 0;
            while (fast!=slow){
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};
