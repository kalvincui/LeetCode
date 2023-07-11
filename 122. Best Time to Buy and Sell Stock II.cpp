class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 2 3 4 10000
        // 1 + 1 + 10000 - 4
        // 10000 - 2
        //Intuition:
        //Ideal situation: Low Price Followed by a very High price, for the entire input
        //Considerations:
        //Low prices and high prices are spread far apart
        //At most you can hold one share of stock, meaning that if you hold a very low price, you could potentially be missing out on transactions between
        //Example:
        // 1, 2, 100000, 3, 100000, 100001
        //If you had a algo that just takes lowest and highest, you would be making substantially less
        // 100001 - 1 vs (100000 - 2  + 100000 - 3)
        //Idea: Anytime there is a price that is higher than the current price, sell
        //Reset the current price 
        int minprice = INT_MAX;
        int profit = 0;
        for (int i = 0; i<prices.size(); i++){
            minprice = min (prices[i], minprice);
            if (prices[i] - minprice > 0){
                profit += (prices[i] - minprice);
                minprice = prices[i];
            }
        }
        return profit;
    }
};
