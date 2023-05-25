class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int del = 0;
        int longest = 0;
        while (j<nums.size()){
            if (nums[j] == 0){
                del++;
            }
            while (del > 1){
                if (nums[i] == 0){
                    del--;
                }
                i++;
            }
            longest = max (longest, j-i);
            j++;
        }
        return longest;
    }
};
