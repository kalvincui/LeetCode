class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;
        for (int i = 0; i<nums.size(); i++){
            if (i%2 == 0){
                even.push_back(nums[i]);
            }else {
                odd.push_back(nums[i]);
            }
        }
        sort (even.begin(), even.end());
        sort (odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        vector<int> res;
        for (int i = 0; i<nums.size(); i++){
            if (i%2 == 0){
                res.push_back(even[i/2]);
            }else {
                res.push_back(odd[i/2]);
            }
        }
        return res;
    }
};
