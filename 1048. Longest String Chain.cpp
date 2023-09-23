class Solution {
public:
    static bool compare (string s1, string s2){
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort (words.begin(), words.end(), compare);
        unordered_map <string, int> dp;
        int ans = 0;
        for (int i = 0; i<words.size(); i++){
            dp[words[i]] = 1;
            for (int j = 0; j<words[i].size(); j++){
                string prev = words[i].substr(0, j) + words[i].substr(j+1);
                if (dp.find(prev) != dp.end()){
                    dp[words[i]] = max(dp[words[i]], dp[prev] + 1);
                }
            }
            ans = max (ans, dp[words[i]]);
        }
        return ans;
    }
};
