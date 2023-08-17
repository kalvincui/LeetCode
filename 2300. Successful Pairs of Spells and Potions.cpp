class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //Idea: Populate a vector, containing the minimum values needed for
        // potions[i] to be successful
        //Compare the value of spells to those values in the vector in a for loop
        //TLE


        //Another Idea:
        //Sort the potions 
        //Binary search using spells[i] and potions, returning index of min value that satisfies
        //Push back potions.size() - low
        vector <int> pairs;
        sort (potions.begin(), potions.end());
        for (int i = 0; i<spells.size(); i++){
            int low = 0;
            int high = potions.size()-1;
            while (low <= high){
                int mid = low + (high-low)/2;
                if (spells[i] >= int(ceil((double)success/potions[mid]))){
                    high = mid-1;
                }else {
                    low = mid+1;
                }
            }
            pairs.push_back(potions.size()-low);
        }
        return pairs;
    }
};
