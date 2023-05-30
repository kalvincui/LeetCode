class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer;
        unordered_set <int> numset1(nums1.begin(), nums1.end());
        unordered_set <int> numset2 (nums2.begin(), nums2.end());
        vector<int> answer0;
        vector<int> answer1;
        for (auto i : numset1){
            if (numset2.find(i) == numset2.end()){
                answer0.push_back(i);
            }
        }
        for (auto i : numset2){
            if (numset1.find(i) == numset1.end()){
                answer1.push_back(i);
            }
        }
        answer.push_back(answer0);
        answer.push_back(answer1);
        return answer;
    }
};
