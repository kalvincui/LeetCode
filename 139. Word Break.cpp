//TLE (brute force)
class Solution {
public:
    bool ans = false;
    bool wordBreak(string s, vector<string>& wordDict) {
        findWord(s, "", wordDict);
        return ans;
    }
    void findWord (string s, string str, vector<string>& wordDict){
        if (s == str){
            ans = true;
            return;
        }
        if (str.length() >= s.length()){
            return;
        }
        for (int i = 0; i<wordDict.size(); i++){
            findWord(s, str+wordDict[i], wordDict);
        }
        return;
    }
};

//DP solution
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector <bool> dp (s.size()+1, false);
        dp[s.size()] = true;
        for (int i = s.size()-1; i>=0; i--){
            for (int j = 0; j<wordDict.size(); j++){
                if (i+wordDict[j].size() > s.size()){
                    continue;
                }
                if (s.substr(i, wordDict[j].size()) == wordDict[j]){
                    dp[i] = dp[i+wordDict[j].size()];
                    if (dp[i]){
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};
