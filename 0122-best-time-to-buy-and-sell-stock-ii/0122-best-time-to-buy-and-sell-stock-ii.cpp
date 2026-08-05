class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int sell = 0;

        for(int i = 1; i < prices.size(); i++){
            int newBuy = max(buy, sell - prices[i]);
            int newSell = max(sell, buy + prices[i]);

            buy = newBuy;
            sell = newSell;
        }
        return sell;
    }
};