class Solution {
public:
    int longestValidParentheses(string s) {
        stack <int> st;
        int longest = 0;
        for (int i = 0; i<s.size(); i++){
            if (s[i] == '('){
                st.push(i);
            }else {
                if (!st.empty() && s[st.top()] == '('){
                        st.pop();
                }else {
                    st.push(i);
                }
            }
        }
        if (st.empty()){
            return s.size();
        }else {
            int start = 0;
            int end = s.size();
            while (!st.empty()){
                start = st.top();
                longest = max (longest, end-start-1);
                end = start;
                st.pop();
            }
            longest = max (longest, end);
        }
        return longest;
    }
};
