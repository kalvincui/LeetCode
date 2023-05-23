class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxavg = numeric_limits<double>::lowest();
        double avg = 0;
        for (int i = 0; i<k-1; i++){
            avg += nums[i];
        }
        int lower = 0;
        int upper = k-1;
        while (upper < nums.size()){
            avg += nums[upper];
            maxavg = max(maxavg, avg/k);
            avg -= nums[lower];
            upper++;
            lower++;
        }
        return maxavg;
    }
};
