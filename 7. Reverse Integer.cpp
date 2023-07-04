public:
    int reverse(int x) {
        int output = 0;
        while (x!=0){
            int digit = x % 10;
            x/=10;
            if (output > INT_MAX/10 || (output == INT_MAX/10 && digit > 7)){
                return 0;
            }
            if (output < INT_MIN/10 || (output == INT_MIN / 10 && digit < -8)){
                return 0;
            }
            output *=10;
            output += digit;
        }
        return output;
    }
