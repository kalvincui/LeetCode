class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int num1temp = 0;
        int num2temp = 0;
        while (num1temp < nums1.size() && num2temp < nums2.size()){
            if (nums1[num1temp] < nums2[num2temp]){
                merged.push_back(nums1[num1temp]);
                num1temp ++;
            }else {
                merged.push_back(nums2[num2temp]);
                num2temp++;
            }
        }
        if (num1temp == nums1.size() && num2temp !=nums2.size()){
            for (int i = num2temp; i<nums2.size(); i++){
                merged.push_back(nums2[i]);
            }
        }
        if (num2temp == nums2.size() && num1temp != nums1.size()){
            for (int i = num1temp; i<nums1.size(); i++){
                merged.push_back(nums1[i]);
            }
        }
        if (merged.size() % 2== 0){
            return (merged[merged.size()/2] + merged[merged.size()/2 - 1]) / 2.0;
        }
        return merged[merged.size()/2];
    }
};
