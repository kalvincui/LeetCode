class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort (piles.begin(), piles.end());
        int low = 1;
        int high = piles[piles.size()-1];
        int ans = high;
        while (low<=high){
            int mid = (low + high)/2;
            if (canFinish (piles, h, mid)){
                ans = mid;
                high = mid-1;
            }else {
                low = mid+1;
            }
        }
        return ans;
    }
    bool canFinish(vector<int>& piles, int h, int k){
        long time = 0;
        for (int i = 0; i<piles.size(); i++){
            if (piles[i]%k){
                time++;
            }
            time += piles[i]/k;
        }
        return (time<=h);
    }
};
