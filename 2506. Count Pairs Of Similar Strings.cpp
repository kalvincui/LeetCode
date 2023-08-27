class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i<words.size(); i++){
            for (int j = i+1; j<words.size(); j++){
                if (isSimilar(words[i], words[j])){
                    ans++;
                }
            }
        }
        return ans;
    }
    bool isSimilar (string s1, string s2){
        unordered_set <char> check1;
        unordered_set<char> check2;
        for (int i = 0; i<s1.size(); i++){
            check1.insert(s1[i]);
        }
        for (int j = 0; j<s2.size(); j++){
            check2.insert(s2[j]);
        }
        return check1 == check2;
    }
};
