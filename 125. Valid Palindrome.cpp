class Solution {
public:
    bool isPalindrome(string s) {
        //Use isalnum method
        //Do 2 pointer method to check if it is a palindrome
        string str = "";
        for (int i = 0; i<s.size(); i++){
            if (isalnum(s[i])){
                str += tolower(s[i]);
            }
        }
        int lo = 0;
        int hi = str.size()-1;
        while (lo <= hi){
            if (str[lo] != str[hi]){
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }
};
