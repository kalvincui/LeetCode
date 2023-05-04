class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int idx = 0;
        string output = "";
        while (idx < word1.size() && idx < word2.size()){
            output += word1[idx];
            output += word2[idx];
            idx++;
        }
        while (idx < word1.size()){
            output += word1[idx];
            idx++;
        }
        while (idx < word2.size()){
            output += word2[idx];
            idx++;
        }
        return output;
    }
};

//Alternative Solution
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int idx = 0;
        string output = "";
        while (idx < word1.size() || idx < word2.size()){
            if (idx < word1.size()){
                output += word1[idx];
            }
            if (idx < word2.size()){
                output += word2[idx];
            }
            idx++;
        }
        return output;
    }
};
