class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        generate (n,n,"", ans);
        return ans;
    }
    void generate (int o, int c, string s, vector <string> & ans){
        if (o == 0){
            for (int i = 0; i<c; i++){
                s += ')';
            }
            ans.push_back (s);
        }else {
            if (o == c){
                generate (o-1,c, s + '(', ans);
            }else {
                generate (o-1,c,s + '(', ans);
                generate (o,c-1,s + ')', ans);
            }
        }
    }
};
