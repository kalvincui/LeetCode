class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector<int>> ans;
        sort (nums.begin(), nums.end());
        if (nums.size()<4){
            return ans;
        }
        for (int i = 0; i<nums.size()-3; i++){
            if (nums[i] > 0 && target < 0){
                break;
            }
            for (int j = i+1; j<nums.size()-2; j++){
                int start = j+1;
                int end = nums.size()-1;
                while (start < end){
                    if (nums[i] + nums[j] > target - nums[start] - nums[end]){
                        end--;
                    }else if (nums[i] + nums[j] < target - nums[start] - nums[end]){
                        start++;
                    }else {
                        vector<int> quad = {nums[i], nums[j], nums[start], nums[end]};
                        ans.push_back(quad);
                        while (nums[start] == quad[2] && end > start){
                            start++;
                        }
                        while (nums[end] == quad[3] && end > start){
                            end--;
                        }
                    }
                }
                while (j+1 < nums.size() && nums[j+1] == nums[j]){
                    j++;
                }
            }
            while (i+1 < nums.size() && nums[i+1] == nums[i]){
                i++;
            }
        }
        return ans;
    }
};
