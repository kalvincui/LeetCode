class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector <int> ransomMap (26);
        vector <int> magazineMap (26);
        for (int i = 0; i<ransomNote.size(); i++){
            ransomMap[ransomNote[i] - 'a']++;
        }
        for (int i = 0; i<magazine.size(); i++){
            magazineMap[magazine[i] - 'a']++;
        }
        for (int i = 0; i<ransomMap.size(); i++){
            if (ransomMap[i] > magazineMap[i]){
                return false;
            }
        }
        return true;
    }
};
