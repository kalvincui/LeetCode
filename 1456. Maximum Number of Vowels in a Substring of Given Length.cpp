class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels = "aeiou";
        int maxvowels = 0;
        int curvowels = 0;
        for (int i = 0; i<k-1; i++){
            if (vowels.find(s[i])!=std::string::npos){
                curvowels++;
            }
        }
        int idx = 0;
        while (idx + k <= s.size()){
            if (vowels.find(s[idx+k-1])!=std::string::npos){
                curvowels++;
            }
            maxvowels = max(maxvowels, curvowels);
            if (vowels.find(s[idx])!=std::string::npos){
                curvowels--;
            }
            idx++;
        }
        return maxvowels;
    }
};
