class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int max_price = 0;
        int min_price = INT_MAX;
        for (int i = 0; i<prices.size(); i++){
            min_price = min(min_price, prices[i]);
            max_price = max(min_price, prices[i]);
            profit = max (profit, max_price - min_price);
        }
        return profit;
    }
};
