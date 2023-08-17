class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> numbers;
        findCombination(k, n, numbers, 1, 0);
        return ans;
    }
    void findCombination(int k, int n, vector<int>numbers, int start, int sum){
        if (numbers.size() == k){
            if (sum == n){
                ans.push_back(numbers);
            }
            return;
        }
        for (int i = start; i<=9; i++){
            numbers.push_back(i);
            findCombination(k, n, numbers, i+1, sum+i);
            numbers.pop_back();
        }
        return;
    }
};
