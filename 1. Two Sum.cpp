class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> indices;
        for (int i = 0; i<nums.size(); i++){
            for (int j = i+1; j<nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
        return indices;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap <int, int> dictionary;
        for (int i = 0; i<nums.size(); i++){
            dictionary.insert ({nums[i], i});
        }
        for (int i = 0; i<nums.size(); i++){
            int findNum = target - nums[i];
            for (auto itr = dictionary.find(findNum); itr!=dictionary.end(); itr++){
                if (itr->first != findNum){
                    break;
                }
                if (itr->second != i){
                    return {i, itr->second};
                }
            }
        }
        return {-1,-1};
    }
};
