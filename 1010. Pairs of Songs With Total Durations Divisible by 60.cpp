class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //Freq map for every minute % 60
        vector <long int> map (60);
        for (int i = 0; i<time.size(); i++){
            map[time[i]%60]++;
        }
        int count = 0;
        count += ((map[0]-1)*map[0])/2;
        count += ((map[30]-1)*map[30])/2;
        for (int i = 1; i<=29; i++){
            count += (map[i] * map[60-i]);
        }
        return count;
    }
};
