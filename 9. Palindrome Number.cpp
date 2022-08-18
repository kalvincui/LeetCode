class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int lower = 0;
        int upper = s.size()-1;
        while (lower < upper){
            if (s[lower] == s[upper]){
                lower ++;
                upper --;
            }else {
                return false;
            }
        }
        return true;
    }
};
