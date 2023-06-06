class Solution {
public:
    string decodeString(string s) {
        stack <string> chars;
        stack <int> nums;
        string ans = "";
        int num = 0;
        for (auto c : s){
            if (isdigit(c)){
                num = num*10 + (c-'0');
            }else if (isalpha(c)){
                ans += c;
            }else if (c == '['){
                nums.push(num);
                chars.push(ans);
                num = 0;
                ans = "";
            }else if (c==']'){
                string tmp = ans;
                for (int i = 0; i<nums.top()-1; i++){
                    ans += tmp;
                }
                ans = chars.top() + ans;
                chars.pop();
                nums.pop();
            }
        }
        return ans;
    }
};
