class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        string str = "";
        //Odd length
        for (int mid = 0; mid<s.length(); mid++){
            for (int i = 0; mid - i >= 0 && mid+i<s.length(); i++){
                if (s[mid-i] != s[mid+i]){
                    break;
                }
                int len = i *2 + 1;
                if (len > longest){
                    longest  = len;
                    str = s.substr(mid-i, longest);
                }
            }
        }
        //Even length
        for (int mid = 0; mid<s.length()-1; mid++){
            for (int i = 0; mid-i+1>=0 && mid+i<s.length(); i++){
                if (s[mid-i+1] != s[mid+i]){
                    break;
                }
                int len = i*2;
                if (len > longest){
                    longest = len;
                    str = s.substr(mid-i+1,longest);
                }
            }
        }
        return str;
    }
};
