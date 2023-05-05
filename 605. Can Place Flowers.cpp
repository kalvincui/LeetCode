class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int leftadjacent = 0;
        int rightadjacent = 0;
        for (int i = 0; i<flowerbed.size(); i++){
            leftadjacent = (i-1 >= 0) ? flowerbed[i-1] : 0;
            rightadjacent = (i+1 < flowerbed.size()) ? flowerbed[i+1] : 0;
            if (!flowerbed[i] && !leftadjacent && !rightadjacent){
                count++;
                flowerbed[i] = 1;
            }
            if (count >=n){
                break;
            }
        }
        return (count >= n);
    }
};
