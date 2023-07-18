class Solution {
public:
    bool isPowerOfTwo(int n) {
        //Can keep dividing by 2
        //Base case: if n == 0, return false
        //Powers of 2: 1,2,4,8
        //2^-1 = 1/2, 
        //2^-2 = 1/4
        //Input is all integers though, so no need to worry about negative numbers
        if (n == 0){
            return false;
        }
        // if (n == 1){
        //     return true;
        // }
        // if (n%2 == 0){
        //     return isPowerOfTwo(n/2);
        // }
        // return false;
        return ((n==1) || (n%2==0 && isPowerOfTwo(n/2)));
    }
};
