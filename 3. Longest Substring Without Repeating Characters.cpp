class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        for (int i = 0; i<s.length(); i++){
            int index = i;
            string str = "";
            int tempmax = 0;
            while (index < s.length()){
                if (str.find(s[index]) > str.length()){
                    str += s[index];
                    tempmax++;
                }else {
                    break;
                }
                index++;
            }
            if (tempmax > max){
                max = tempmax;
            }
        }
        return max;
    }
};
