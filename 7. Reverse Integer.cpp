class Solution {
public:
    int reverse(int x) {
        int output = 0;
        while (x){
            int digit = x%10;
            x /=10;
            if (output > INT_MAX/10 || output < INT_MIN/10){
                return 0;
            }
            output*=10;
            output += digit;
        }
        return output;
    }
};
