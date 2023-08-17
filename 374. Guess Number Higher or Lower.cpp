/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        //int mid = (low + high) / 2;
        int mid = low + (high-low)/2;
        while (low <= high){
            //mid = (low + high) / 2;
            mid = low + (high-low)/2;
            int g = guess (mid);
            if (g == 0){
                return mid;
            }
            if (g == 1){
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return mid;
    }
};
