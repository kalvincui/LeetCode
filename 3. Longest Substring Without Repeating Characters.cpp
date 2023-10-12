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



//More efficient using a map
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, int> charMap;
        int start = -1;
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (charMap.count(s[i]) != 0) {
                start = max(start, charMap[s[i]]);
            }
            charMap[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        
        return maxLen;
    }
};
