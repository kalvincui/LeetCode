class Solution {
public:
    char findTheDifference(string s, string t) {
        vector <char> freq (26, 0);
        for (int i = 0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }
        for (int i = 0; i<t.size(); i++){
            if (freq[t[i]-'a'] == 0){
                return t[i];
            }
            freq[t[i]-'a']--;
        }
        return -1;
    }
};
