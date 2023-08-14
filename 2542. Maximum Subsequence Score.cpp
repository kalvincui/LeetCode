class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long score = 0;
        vector<pair <int, int>> seq;
        for (int i = 0; i<nums1.size(); i++){
            seq.push_back({nums2[i], nums1[i]});
        }
        sort (seq.begin(), seq.end(), greater<>());
        priority_queue <int, vector<int>, greater<int>> pq;
        long long num1sum = 0;
        for (int i = 0; i<k; i++){
            pq.push(seq[i].second);
            num1sum += seq[i].second;
        }
        score = max (score, num1sum*seq[k-1].first);
        for (int i = k; i<nums1.size(); i++){
            num1sum -= pq.top();
            pq.pop();
            pq.push(seq[i].second);
            num1sum += seq[i].second;
            score = max (score, num1sum*seq[i].first);
        }
        return score;
    }
};
