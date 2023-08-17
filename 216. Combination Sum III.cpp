class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> numbers;
        findCombination(k, n, numbers, 0);
        return ans;
    }
    void findCombination(int k, int n, vector<int>numbers, int sum){
        if (numbers.size() == k){
            if (sum == n){
                sort(numbers.begin(), numbers.end());
                if (find(ans.begin(), ans.end(), numbers) == ans.end()){
                    ans.push_back(numbers);
                }
            }
            return;
        }
        for (int i = 1; i<=9; i++){
            if (find(numbers.begin(), numbers.end(), i) == numbers.end()){
                numbers.push_back(i);
                findCombination(k, n, numbers, sum+i);
                numbers.pop_back();
            }
        }
        return;
    }
};
