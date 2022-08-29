class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() < 1){
            return 0;
        }
        int index = 0;
        while (needle.size() <= haystack.size()-index){
            bool checker = true;
            for (int j = 0; j<needle.size(); j++){
                if (needle[j] == haystack[index+j]){
                    continue;
                }else {
                    checker = false;
                    break;
                }
            }
            if (checker){
                return index;
            }
            index++;
        }
        return -1;
    }
};
