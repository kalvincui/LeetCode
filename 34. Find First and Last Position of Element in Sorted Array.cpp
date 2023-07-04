class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;
        int tempindex = 0;
        while (tempindex < nums.size() && nums[tempindex] <= target){
            if (nums[tempindex] == target){
                start = tempindex;
                break;
            }
            tempindex++;
        }
        tempindex = nums.size()-1;
        while (tempindex >= 0 && nums[tempindex] >= target){
            if (nums[tempindex] == target){
                end = tempindex;
                break;
            }
            tempindex--;
        }
        return {start, end};
    }
};



//Binary Search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = binary_search(nums, nums.size()-1, 0, target);
        int idx2 = binary_search(nums, nums.size()-1, 0, target+1)-1;
        if (idx1 >= 0 && idx1<nums.size() && nums[idx1] == target){
            return {idx1, idx2};
        }
        return {-1, -1};
    }
    int binary_search (vector<int>& nums, int high, int low, int target){
        while (low<=high){
            int mid = (int)(low + high) / 2;
            if (nums[mid] < target){
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return low;
    }
};
