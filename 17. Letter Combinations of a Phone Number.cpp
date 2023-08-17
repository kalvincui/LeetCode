class Solution {
public:
    const vector<string> nums = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector <string> output;
        if (digits.size()<1){
            return output;
        }
        findComb (0,digits,output,"");
        return output;
    }
    void findComb (int idx, string digits, vector<string>& output, string s){
        if (idx == digits.size()){
            output.push_back(s);
        }else {
            for (int i = 0; i<nums[digits[idx]-'0'].size(); i++){
                findComb (idx+1, digits, output, s + nums[digits[idx]-'0'][i]);
            }
        }
    }
};




class Solution {
public:
    unordered_map <char, string> map;   
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        if (digits.size() == 0){
            return ans;
        }
        getCombinations(digits, 0, "");
        return ans;
    }
    void getCombinations (string digits, int idx, string s){
        if (s.size() == digits.size()){
            ans.push_back(s);
            return;
        }
        for (int i = 0; i<map[digits[idx]].size(); i++){
            getCombinations(digits, idx+1, s+map[digits[idx]][i]);
        }
        return;
    }
};
