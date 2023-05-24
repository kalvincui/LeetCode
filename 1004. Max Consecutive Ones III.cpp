class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int longest = 0;
        int zeros = 0;
        while (j < nums.size()){
            if (nums[j] == 0){
                zeros++;
            }
            while (zeros > k){
                if (nums[i] == 0){
                    zeros--;
                }
                i++;
            }
            longest = max (longest, j-i+1);
            j++;
        }
        return longest;
    }
};
