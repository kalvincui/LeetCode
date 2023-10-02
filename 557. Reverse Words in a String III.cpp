class Solution {
public:
    string reverseWords(string s) {
        stack <char> st;
        string output;
        for (int i = 0; i<s.size(); i++){
            if (s[i] == ' '){
                while (!st.empty()){
                    output += st.top();
                    st.pop();
                }
                output += ' ';
            }else {
                st.push(s[i]);
            }
        }
        while (!st.empty()){
            output += st.top();
            st.pop();
        }
        return output;
    }
};
