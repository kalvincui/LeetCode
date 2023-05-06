class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n);
        vector <int> left(n);
        vector <int> right(n);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for (int i = 1; i<n; i++){
            left [i] = (left[i-1] * nums[i]);
        }
        for (int i = n-2; i>=0; i--){
            right[i] = (right[i+1] * nums[i]);
        }
        for (int i = 0; i<=n-1; i++){
            if (i == 0){
                ans[i] = (right[i+1]);
            }else if (i == n-1){
                ans[i] = (left[i-1]);
            }else {
                ans[i] = (left[i-1] * right[i+1]);
            }
        }
        return ans;
    }
};

//Alternative Approach O(1) Space Complexity DP
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};
