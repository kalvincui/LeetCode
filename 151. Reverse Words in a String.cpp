class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        string ans = "";
        for (int i = s.size() -1; i>=0; i--){
            if (s[i] == ' ' && word != ""){
                reverse(word.begin(), word.end());
                if (ans!=""){
                    ans += ' ';
                }
                ans += word;
                word = "";
            }else if (s[i] == ' ' && word == ""){
                continue;
            }else if (s[i] != ' '){
                word += s[i];
            }
        }
        if (word!=""){
            reverse(word.begin(), word.end());
            if (ans!=""){
                ans += ' ';
            }
            ans+= word;
        }
        return ans;
    }
};

//Alternative Solution
string reverseWords(string s) {
        if(s.size() == 0) return s;
        stack<string> stack;
        string result;
        for(int i=0; i<s.size(); i++) {
            string word;
            if(s[i]==' ') continue; //skip spaces
            while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
                word += s[i]; i++;
            }
            stack.push(word); //push word to the stack
        }
        while(!stack.empty()) {
            result += stack.top(); stack.pop();
            if(!stack.empty()) result += " ";
        }
        return result;
    }
};
