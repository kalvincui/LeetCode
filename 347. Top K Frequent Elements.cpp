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


//Alternative solution
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>> pq; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};
