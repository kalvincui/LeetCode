class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string check = "";
        for (int i = 0; i<words.size(); i++){
            if (check.size() >=s.size()){
                break;
            }
            check+= words[i];
        }
        return check == s;
    }
};
