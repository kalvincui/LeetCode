class Solution {
    public:
    bool isValid(string s) {
        stack <char> stack;
        if (s.size() %2 !=0 ){
            return false;
        }
        for (int i = 0; i<s.size(); i++){
            if (s[i] == ')'){
                if (stack.empty()){
                    return false;
                }else if ( stack.top () != '('){
                    return false;
                }else{
                    stack.pop();
                }
            }else if (s[i] == ']'){
                if (stack.empty()){
                    return false;
                }else if ( stack.top () != '['){
                    return false;
                }else{
                    stack.pop();
                }
            }else if (s[i] == '}'){
                if (stack.empty()){
                    return false;
                }else if ( stack.top () != '{'){
                    return false;
                }else{
                    stack.pop();
                }
            }else {
                stack.push(s[i]);
            }
        }
        return stack.empty();
    }
};
