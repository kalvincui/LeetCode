class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        //Pointer for left set and right set
        //Min heap left set and right set
        long long cost = 0;
        priority_queue <int, vector<int>, greater<int>> left;
        priority_queue <int, vector<int>, greater<int>> right;
        for (int i = 0; i<candidates; i++){
            left.push(costs[i]);
        }
        for (int i = costs.size()-1; i>=costs.size()-candidates && i>=candidates; i--){
            right.push(costs[i]);
        }
        int leftptr = candidates;
        int rightptr = costs.size()-candidates-1;
        for (int i = 0; i<k; i++){
            if (left.empty()){
                cost += right.top();
                right.pop();
                if (rightptr >= leftptr){
                    right.push(costs[rightptr--]);
                }
            }
            else if (right.empty()){
                cost+=left.top();
                left.pop();
                if (leftptr <= rightptr){
                    left.push(costs[leftptr++]);
                }
            }
            else if (right.top() < left.top()){
                cost += right.top();
                right.pop();
                if (rightptr >= leftptr){
                    right.push(costs[rightptr--]);
                }
            }else { 
                cost+=left.top();
                left.pop();
                if (leftptr <= rightptr){
                    left.push(costs[leftptr++]);
                }
            }
        }
        return cost;
    }
};
