class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int pivot= start;
        while (start < end){
            if (nums[start] <= nums[end]){
                pivot = start;
                break;
            }
            start++;
        }
        cout << pivot;
        if (pivot == 0){
            for (int i = 0; i<nums.size(); i++){
                if (nums[i] == target){
                    return i;
                }else if (nums[i] > target){}
            }
        }else {
            while (pivot >=0 && pivot < nums.size()){
            if (target == nums[pivot]){
                return pivot;
            }else if (target > nums[pivot] && target >nums[end]){
                while (pivot >= 0){
                    if (target == nums[pivot]){
                        return pivot;
                    }
                    pivot--;
                }
                return -1;
            }else{
                while (pivot < nums.size()){
                    if (target == nums[pivot]){
                        return pivot;
                    }
                    pivot++;
                }
                return -1;
            }
        }
        }
        return -1;
    }
};
