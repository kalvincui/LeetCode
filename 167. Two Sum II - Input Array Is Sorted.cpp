class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //2 Pointer Question?
        //Sorted in non-decreasing order
        //1-indexed array (add 1 to each of the indexes at the end)
        //Exactly one solution
        //Could have low and high pointers
        //Increase low pointer if target > low + high
        //Decrease high pointer if target < low + high
        int low = 0;
        int high = numbers.size()-1;
        while (low <= high){
            if (numbers[low] + numbers[high] == target){
                return {low+1, high+1};
            }
            if (numbers[low] + numbers[high] > target){
                high--;
            }
            if (numbers[low] + numbers[high] < target){
                low++;
            }
        }
        return {0, 0};
    }
};
