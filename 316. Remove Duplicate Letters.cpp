class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map <char, int> freq;
        unordered_map <char, bool> visited;
        stack <char> st;
        string ans = "";
        for (int i = 0; i<s.size(); i++){
            freq[s[i]]++;
            visited[s[i]] = false;
        }
        for (int i = 0; i<s.size(); i++){
            freq[s[i]]--;
            if (visited[s[i]]){
                continue;
            }
            while (!st.empty() && st.top() > s[i] && freq[st.top()] > 0){
                visited[st.top()] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]] = true;
        }
        while (!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//Alternative solution less memory
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector <int> lastindex (26, 0);
        unordered_map <char, bool> visited;
        stack <char> st;
        string ans = "";
        for (int i = 0; i<s.size(); i++){
            lastindex[s[i] - 'a'] = i;
            visited[s[i]] = false;
        }
        for (int i = 0; i<s.size(); i++){
            if (visited[s[i]]){
                continue;
            }
            while (!st.empty() && st.top() > s[i] && lastindex[st.top() - 'a'] > i){
                visited[st.top()] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]] = true;
        }
        while (!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
