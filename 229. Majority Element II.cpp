class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        set <int> ans;
        vector<int> res;
        for (int i = 0; i<nums.size(); i++){
            map[nums[i]]++;
            if (map[nums[i]] > nums.size()/3){
                ans.insert(nums[i]);
            }
        }
        for (auto itr = ans.begin(); itr!=ans.end(); itr++){
            res.push_back(*itr);
        }
        return res;
    }
};
