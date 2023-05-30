class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int max_altitude = 0;
        for (auto i : gain){
            altitude += i;
            max_altitude = max (max_altitude, altitude);
        }
        return max_altitude;
    }
};
