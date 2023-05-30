class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int, int> freq;
        for (int i = 0; i<arr.size(); i++){
            auto itr = freq.find(arr[i]);
            if (itr == freq.end()){
                freq.insert({arr[i], 1});
            }else {
                itr->second = itr->second + 1;
            }
        }
        unordered_set <int> check;
        for (auto itr: freq){
            if (check.find(itr.second) != check.end()){
                return false;
            }
            check.insert(itr.second);
        }
        return true;
    }
};
