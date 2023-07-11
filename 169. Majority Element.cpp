class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Create a freq map
        //Iterate through the map, since majoriy element always exists, just keep track of the highest frequency element
        unordered_map <int, int> freq;
        for (int i = 0; i<nums.size(); i++){
            auto itr = freq.find(nums[i]);
            if (itr != freq.end()){
                itr->second = itr->second + 1;
            }else {
                freq.insert({nums[i], 1});
            }
        }
        int n = 0;
        int ans = nums[0];
        for (auto itr = freq.begin(); itr!=freq.end(); itr++){
            if (itr->second > n){
                ans = itr->first;
                n = itr->second;
            }
        }
        return ans;
    }
};
