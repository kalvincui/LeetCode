class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //All numbers are positive
        //target is positive as well
        //Could keep a running count of the sum
        //If the sum is <target, you increase window size aka adding another number to the sum
        //If the sum is > than the target, you remove the  elements you added originally to the sum (FIFO) until the sum is <= target
        //Datastructure you could use to keep track of the sum could be an int and a queue
        //Even if the target is reached, keep iterating as it is possible there is an even shorter subarray
        //Idea: Add number to sum, if sum > target, start subtracting numbers from the queue until the sum <= target, if sum = target, record the
        //length of the queue + 1 (current element)
        queue <int> q;
        int sum = 0;
        int minlength = nums.size()+1;
        int idx = 0;
        while (idx < nums.size()){
            sum += nums[idx];
            q.push(nums[idx]);
            if (sum >= target){
                while (!q.empty() && sum>= target){
                    minlength = min (minlength, (int)q.size());
                    sum -= q.front();
                    q.pop();
                }
            }
            idx++;
        }
        if (minlength > nums.size()){
            return 0;
        }
        return minlength;
    }
};
