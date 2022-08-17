class Solution {
public:
    int myAtoi(string s) {
        int index = s.find_first_not_of(' ');
        if (index > s.size()){
            return 0;
        }
        bool negative = false;
        bool positive = false;
        int output = 0;
        string temp ="";
        if (s[index] == '-'){
            negative = true;
            index++;
        }else if (s[index] == '+'){
            positive = true;
            index++;
        }else if (!isdigit(s[index])){
            return output;
        }
        while (index < s.size() && isdigit(s[index])){
            temp += s[index];
            index++;
        }
        if (temp == ""){
            return output;
        }
        try{
            output = stoi(temp);
            if (negative){
                output *=-1;
            }
        }catch (std::out_of_range){
            if (negative){
                output = -2147483648;
            }else {
                output = 2147483647;
            }
        }
        return output;
    }
};
