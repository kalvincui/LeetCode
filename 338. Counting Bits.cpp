class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans;
        int32_t holder = 0;
        for (int i = 0; i<=n; i++){
            int32_t temp = holder;
            int ones = 0;
            while (temp != 0){
                if (temp&1 == 1){
                    ones++;
                }
                temp = temp >>1;
            }
            ans.push_back(ones);
            holder++;
        }
        return ans;
    }
};



//Alternative Solution that is Faster (simplifying while loop)
class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans;
        int32_t holder = 0;
        for (int i = 0; i<=n; i++){
            int32_t temp = holder;
            int ones = 0;
            while (temp != 0){
                temp = temp&(temp-1);
                ones++;
            }
            ans.push_back(ones);
            holder++;
        }
        return ans;
    }
};
