class Solution {
public:
    string reverseVowels(string s) {
        string check = "aAeEiIoOuU";
        string vowels = "";
        for (int i = 0; i<s.size(); i++){
            if (check.find(s[i])!= string::npos){
                vowels += s[i];
            }
        }
        int idx = 0;
        for (int i = s.size()-1; i>=0; i--){
            if (check.find(s[i])!= string::npos){
                s[i] = vowels[idx];
                idx++;
            }
        }
        return s;
    }
};

//Alternative Solution
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
