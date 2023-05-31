class Solution {
public:
    bool closeStrings(string word1, string word2) {
        //must be same length
        //must contain same characters
        //record freq of every character in map
        //iterate through word1, if character doesn't match word2, can maybe swap, subtract -1 from each frequency
        //compare word1 and word2 characters. if they are the same but different frequencies, needa replace with different letter
        //if they are different with same frequencies, swap
        //if they are different with different frequncies, need to swap
        //in the end, you just need both the maps to have the same frequencies, by swapping around the frequncies of 1 of the map only
        if (word1.size() != word2.size()){
            return false;
        }
        map <char, int> word1map;
        map <char, int> word2map;
        set <char> word1characters;
        set <char> word2characters;
        multiset <int> word1freq;
        multiset <int> word2freq;
        for (int i = 0; i<word1.size(); i++){
            auto word1itr = word1map.find(word1[i]);
            if (word1itr == word1map.end()){
                word1map.insert({word1[i], 1});
            }else {
                word1itr->second = word1itr->second + 1;
            }
            auto word2itr = word2map.find(word2[i]);
            if (word2itr == word2map.end()){
                word2map.insert({word2[i], 1});
            }else {
                word2itr->second = word2itr->second+1;
            }
            word1characters.insert(word1[i]);
            word2characters.insert(word2[i]);
        }
        if (word1characters != word2characters){
            return false;
        }
        for (auto itr = word1map.begin(); itr!=word1map.end(); itr++){
            word1freq.insert(itr->second);
        }
        for (auto itr = word2map.begin(); itr!=word2map.end(); itr++){
            word2freq.insert(itr->second);
        }
        return (word1freq == word2freq);
    }
};


//Alternative Solution
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector <int> word1freq(26,0), word2freq(26,0);
        set<char>word1char, word2char;
        if (word1.size() != word2.size()){
            return false;
        }
        for (int i = 0; i<word1.size(); i++){
            word1freq[word1[i]-'a']++;
            word2freq[word2[i] - 'a']++;
            word1char.insert(word1[i]);
            word2char.insert(word2[i]);
        }
        sort (word1freq.begin(), word1freq.end());
        sort (word2freq.begin(), word2freq.end());
        return (word1freq == word2freq && word1char == word2char);
    }
};
