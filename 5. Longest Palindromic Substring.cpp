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


//DP Solution
class Solution {
public:
    string longestPalindrome(string s) {
        int length = 1;
        int start =0;
        vector<vector<int>> dp (s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i<s.size(); i++){
            dp[i][i] = 1;
        }
        for (int i = 0; i<s.size()-1; i++){
            if (s[i] == s[i+1]){
                dp[i][i+1] = 1;
                start = i;
                length = 2;
            }
        }
        for (int k = 3; k<=s.size(); k++){
            for (int i = 0; i <s.size()-k+1; i++){
                int j = i+k-1;
                if (dp[i+1][j-1] && s[i] == s[j]){
                    dp[i][j] = true;
                    if (k>length){
                        start = i;
                        length = k;
                    }
                }
            }
        }
        return s.substr(start, length);
    }
};
