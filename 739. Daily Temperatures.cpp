class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //2 stacks, one of them being monotonic (temperatures), and other just a regular stack being the indices of the temperatures
        vector<int> ans (temperatures.size(), 0);
        stack <int> indices;
        stack <int> temps;
        for (int i = 0; i<temperatures.size(); i++){
            while (!temps.empty() && temps.top() < temperatures[i]){
                ans[indices.top()] = i - indices.top();
                indices.pop();
                temps.pop();
            }
            indices.push(i);
            temps.push(temperatures[i]);
        }
        return ans;
    }
};
