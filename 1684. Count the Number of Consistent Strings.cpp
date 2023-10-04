class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        vector <bool> allow (26, false);
        for (int i = 0; i<allowed.size(); i++){
            allow[allowed[i]-'a'] = true;
        }
        for (int i = 0; i<words.size(); i++){
            bool check = true;
            for (int j = 0; j<words[i].size(); j++){
                if (!allow[words[i][j]-'a']){
                    check = false;
                    break;
                }
            }
            if (check){
                res++;
            }
        }
        return res;
    }
};
