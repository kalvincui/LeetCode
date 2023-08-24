class Solution {
public:
    int numTilings(int n) {
        vector <long long> ans (n+3, 0);
        ans[1] = 1;
        ans[2] = 2;
        ans[3] = 5;
        for (int i = 4; i<=n; i++){
            ans[i] = 2*ans[i-1] + ans[i-3];
            ans[i] = ans[i] % 1000000007;
        }
        return ans[n];
    }
};
