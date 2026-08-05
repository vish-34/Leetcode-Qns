class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int sell = INT_MIN;
        int rest = 0;

        for(int i = 1; i < prices.size(); i++){
            int prevbuy = buy;
            int prevsell = sell;
            int prevrest = rest;

            buy = max(prevbuy, prevrest - prices[i]);
            sell = prevbuy + prices[i];
            rest = max(prevrest, prevsell);
        }
        return max(rest, sell);
    }
};