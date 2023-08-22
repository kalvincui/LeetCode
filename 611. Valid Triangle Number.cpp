class Solution {
public:
    int ans = 0;
    int triangleNumber(vector<int>& nums) {
        //Triangle is valid only if sum of any two sides is greater than third side for all sides
        //Brute force check every possible triplet for this condition
        //How do you get every possible triplet?
        //Sort the nums, so it goes in ascending order
        //Use recursion to get all possible triplets
        //TLE but gives right answer
        sort (nums.begin(), nums.end());
        vector<int> triplet;
        testTriplets(nums, triplet, 0);
        return ans;
    }
    void testTriplets (vector<int>& nums, vector<int> t, int idx){
        if (nums.size() <3){
            return;
        }
        if (t.size() == 3){
            if (t[0] + t[1] > t[2] && t[0] + t[2] > t[1] && t[1] + t[2] > t[0]){
                ans++;
            }
            return;
        }
        for (int i = idx; i<nums.size(); i++){
            t.push_back(nums[i]);
            testTriplets(nums, t, i+1);
            t.pop_back();
        }
    }
};


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort (nums.begin(), nums.end());
        for (int k = 2; k<nums.size(); k++){
            int i = 0;
            int j = k-1;
            while (i<j){
                if (nums[i] + nums[j] > nums[k]){
                    ans += j-i;
                    j--;
                }else {
                    i++;
                }
            }
        }
        return ans;
    }
};
