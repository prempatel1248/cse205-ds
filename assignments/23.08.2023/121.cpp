class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minprice=prices[0];
        for(int i=0; i<prices.size(); i++){
            if(minprice>prices[i]){
                minprice=prices[i];
            }
            if(profit<prices[i]-minprice){
                profit=prices[i]-minprice;
            }
        }
        return profit;
    }
};