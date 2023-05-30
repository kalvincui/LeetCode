//My original Solution
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivotindex = 0;
        if (nums.size() == 0){
            return -1;
        }
        while (pivotindex < nums.size()){
            int leftsum = 0;
            int rightsum = 0;
            for (int i = 0; i<pivotindex; i++){
                leftsum += nums[i];
            }
            for (int i = pivotindex+1; i<nums.size(); i++){
                rightsum += nums[i];
            }
            if (leftsum == rightsum){
                return pivotindex;
            }
            pivotindex ++;
        }
        return -1;       
    }
};

//My updated Solution
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum [nums.size()];
        int total = 0;
        for (int i = 0; i<nums.size(); i++){
            total += nums[i];
            leftSum[i] = total;
        }
        int idx = 0;
        while (idx < nums.size()){
            if (leftSum[idx] - nums[idx] == total-leftSum[idx]){
                return idx;
            }
            idx++;
        }
        return -1;
    }
};

//FASTER SOLUTION
// Time Complexity : O(n)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Initialize rightSum to store the sum of all the numbers strictly to the index's right...
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        // Initialize leftSum to store the sum of all the numbers strictly to the index's left...
        int leftSum = 0;
        // Traverse all elements through the loop...
        for (int idx = 0; idx < nums.size(); idx++) {
            // subtract current elements with from rightSum...
            rightSum -= nums[idx];
            // If the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right...
            if (leftSum == rightSum)
                return idx;     // Return the pivot index...
            // add current elements with leftSum...
            leftSum += nums[idx];
        }
        return -1;      // If there is no index that satisfies the conditions in the problem statement...
    }
};
