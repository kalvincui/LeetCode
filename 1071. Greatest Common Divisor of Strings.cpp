class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len = 1;
        string gcd = "";
        while (len <= str1.size() && len<=str2.size()){
            string divisor = str2.substr(0, len);
            int count1 = 0;
            int count2 = 0;
            int m = divisor.size();
            int n = str1.size();
            for (int i = 0; i<=n-m; i+=m){
                int j;
                for (j = 0; j<m; j++){
                    if (str1[i+j] != divisor[j]){
                        break;
                    }
                }
                if (j == m){
                    count1++;
                }
            }
            n = str2.size();
            for (int i = 0; i<=n-m; i+=m){
                int j;
                for (j = 0; j<m; j++){
                    if (str2[i+j] != divisor[j]){
                        break;
                    }
                }
                if (j == m){
                    count2++;
                }
            }
            if ((count1 * len == str1.size()) && (count2 * len == str2.size())){
                gcd = divisor;
            }
            len++;
        }
        return gcd;
    }
};

//Alternative Solution
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)? 
        str1.substr(0, gcd(size(str1),size(str2))): "";
    }
};
