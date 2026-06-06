class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for(int i = 0; i < prices.size(); ++i){
            int discount = 0;
            for(int j = i + 1; j < prices.size(); ++j){
                if(prices[j] <= prices[i]){
                    discount = prices[j];
                    break;
                }
            }
            prices[i] -= discount;
        }
        return prices;
    }
};