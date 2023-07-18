class Solution {
public:
    bool isPowerOfFour(int n) {
        //Same ideas as Power of Two and Power of Three
        if (n == 0){
            return false;
        }
        return n==1 || (n%4 ==0 && isPowerOfFour(n/4));
    }
};
