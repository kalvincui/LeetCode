class Solution {
public:
    string removeStars(string s) {
        stack <char> str;
        int idx = 0;
        while (idx < s.size()){
            if (s[idx] == '*'){
                str.pop();
            }else {
                str.push(s[idx]);
            }
            idx++;
        }
        stack <char> ansstack;
        while (!str.empty()){
            ansstack.push(str.top());
            str.pop();
        }
        string ans = "";
        while (!ansstack.empty()){
            ans += ansstack.top();
            ansstack.pop();
        }
        return ans;
    }
};
