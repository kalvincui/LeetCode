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
