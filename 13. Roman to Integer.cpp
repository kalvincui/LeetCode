#include <map>

class Solution {
public:
    int romanToInt(string s) {
        map <char, int> numerals = {{'I',1}, {'V',5}, {'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int total = 0;
        for (int i = 0; i<s.length(); i++){
            char temp1 = s[i];
            int num2 = 0;
            if (i+1<s.length()){
                char temp2 = s[i+1];
                for (map<char,int>::iterator itr = numerals.begin(); itr!=numerals.end(); ++itr){
                    if ((*itr).first == temp2){
                        num2 = (*itr).second;
                        break;
                    }
                }
            }
            int num1;
            for (map<char,int>::iterator itr = numerals.begin(); itr!=numerals.end(); ++itr){
                if ((*itr).first == temp1){
                    num1 = (*itr).second;
                    break;
                }
            }
        if (num1 < num2){
            total += (num2 - num1);
            i++;
        }else {
            total += num1;
            }
        }
        return total;
    }
};
