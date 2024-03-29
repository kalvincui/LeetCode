class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        string check = "";
        while (idx < t.size()){
            if (s.find(t[idx]) != std::string::npos){
                check += t[idx];
            }
            idx++;
        }
        idx = 0;
        int checkidx = 0;
        while (idx < s.size() && checkidx < check.size()){
            if (s[idx] == check[checkidx]){
                idx++;
            }
            checkidx++;
        }
        return checkidx == check.size() && idx == s.size();
    }
};

//Alternative Solution
**# Recursive Approach**

The idea is simple, we traverse both strings from one side to other side (say from rightmost character to leftmost). If we find a matching character, we move ahead in both strings. Otherwise we move ahead only in str2.

Code:
class Solution {
public:
    bool isSubSeq(string str1, string str2, int m, int n) 
{ 
    // Base Cases 
    if (m == 0) return true; 
    if (n == 0) return false; 
    // If last characters of two strings are matching 
    if (str1[m-1] == str2[n-1]) 
        return isSubSeq(str1, str2, m-1, n-1); 
    // If last characters are not matching 
    return isSubSeq(str1, str2, m, n-1); 
} 
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        return isSubSeq(s,t,m,n);
    }
};


// Approach Using TWO POINTER

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == m ? 1 : 0;
    }
};


//  USING DYNAMIC PROGRAMMING 
// if LCS of string A  nd B is equal to Size of String A then its True else false;

class Solution {
public:
    int helper(string x, string y) {
        int m = x.size();
        int n = y.size();
        int dp[m+1][n+1];
        for(int i = 0; i<=m; i++)
        {
            dp[i][0]=0;
        }
        for(int i = 0; i<=n; i++)
        {
            dp[0][i]=0;
        }
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    bool isSubsequence(string smaller, string larger) {

        int x  = helper(smaller,larger);
        if(x == smaller.size()){
            return true;
        }
        return false;      
    }
};




class Solution {
public:
    bool isSubsequence(string s, string t) {
        //Two pointers, one keeping track of s index and one for t index
        //Nested while loops, iterating through s, with inner while loop for t
        int s_index = 0;
        int t_index = 0;
        while (s_index < s.size()){
            if (t_index >= t.size()){
                return false;
            }
            while (t_index < t.size()){
                if (s[s_index] == t[t_index]){
                    break;
                }
                t_index++;
            }
            t_index++;
            s_index++;
        }
        return t_index <= t.size();
    }
};
