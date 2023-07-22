class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //Number of Content Children is the Number of Elements in S >= G
        //2 Pointer Method
        //Sort G and S
        //2 Pointer Method
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int gidx = 0;
        int sidx = 0;
        while (gidx < g.size() && sidx < s.size()){
            if (s[sidx] >= g[gidx]){
                ans++;
                gidx++;
            }
            sidx++;
        }
        return ans;
    }
};
