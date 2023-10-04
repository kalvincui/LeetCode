class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int sum = 0;
        int j = 0;
        int res = 0;
        for (int i = 0; i<nums.size(); i++){
            while ((sum & nums[i])!=0){
                sum^=nums[j++];
            }
            sum |= nums[i];
            res = max(res,i-j+1);
        }
        return res;
    }
};
