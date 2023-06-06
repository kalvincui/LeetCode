bool cmp (pair<int,int>&a, pair<int,int>&b){
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> sol;
        map <int, int> freqmap;
        for (int i = 0; i<nums.size(); i++){
            auto itr = freqmap.find(nums[i]);
            if (itr == freqmap.end()){
                freqmap.insert({nums[i], 1});
            }else {
                itr->second = itr->second + 1;
            }
        }
        vector <pair<int, int>> sortedfreqmap;
        for (auto it : freqmap){
            sortedfreqmap.push_back(it);
        }
        sort (sortedfreqmap.begin(), sortedfreqmap.end(), cmp);
        int count = 0;
        for (auto itr : sortedfreqmap){
            if (count == k){
                break;
            }
            sol.push_back(itr.first);
            count++;
        }
        return sol;
    }
};
