class Solution {
public:
    bool isPowerOfThree(int n) {
        //1, 3, 9, 27...
        //Base case: if n == 1, return true
        //If n%3 == 0, recursive call n/3 <--- 0 is an edge case, check for it explicity?
        //Else return false
        if (n == 0){
            return false;
        }
        return n==1 || (n%3 == 0 && isPowerOfThree(n/3));
    }
};
