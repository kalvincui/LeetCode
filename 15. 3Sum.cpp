class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        sort (nums.begin(), nums.end());
        for (int i = 0; i<nums.size(); i++){
            int start = i+1;
            int end = nums.size()-1;
            if (nums[i] > 0){
                break;
            }
            while (start < end){
                if (nums[i] + nums[start] > 0){
                    break;
                }
                if (nums[i] + nums[start] + nums[end] < 0){
                    start++;
                }else if (nums[i] + nums[start] + nums[end] > 0){
                    end--;
                }else{
                    vector<int> triplet = {nums[i], nums[start], nums[end]};
                    output.push_back(triplet);
                    while (nums[start] == triplet[1] && start < end){
                        start++;
                    }
                    while (nums[end] == triplet[2] && end > start){
                        end--;
                    }
                }
            }
            while (i+1 < nums.size() && nums[i+1] == nums[i]){
                i++;
            }
        }
        return output;
    }
};
