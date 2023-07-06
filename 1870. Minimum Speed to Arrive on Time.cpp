class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = (int)pow(10, 7);
        int ans = -1;
        while (low <= high){
            int mid = (low+high)/2;
            if (canArrive(dist, hour, mid)){
                ans = mid;
                high = mid-1;
            }else {
                low = mid+1;
            }
        }
        return ans;
    }
    bool canArrive(vector<int>& dist, double hour, int speed){
        double time = 0;
        for (int i = 0; i<dist.size(); i++){
            if (i == dist.size()-1){
                time += 1.0 * dist[i]/speed;
            }else {
                if (dist[i]%speed){
                    time++;
                }
                time += dist[i]/speed;
            }
        }
        return (time <= hour);
    }
};
