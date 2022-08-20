class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output = "";
        int index = 0;
        while (index < strs[0].size()){
            char temp = strs[0][index];
            for (int i = 1; i<strs.size(); i++){
                if (index >= strs[i].size() || strs[i][index] !=temp){
                    return output;
                }
            }
            output += temp;
            index++;
        }
        return output;
    }
};
