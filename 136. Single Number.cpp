class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        sort (nums.begin(), nums.end());
        for (int i = 0; i<nums.size(); i+=2){
            if (nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return nums[nums.size()-1];
    }
};


//Alternative Solution Using Bitwise XOR Operator (NUM1 XOR NUM1 = 0, 0 XOR NUM1 = NUM1)
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   for(auto x:nums)
	   ans^=x;
	   return ans;
    }
};
