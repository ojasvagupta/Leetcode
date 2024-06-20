class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int sell=0;
        int profit=0;
        int totprofit=0;
        for(int i=1;i<prices.size();i++)
        {
            if (buy>=prices[i])
            {
                buy=prices[i];
            }
            else
            {
                sell=prices[i];
                profit=sell-buy;
                totprofit=profit+totprofit;
                buy=prices[i];
            }
        }
        return totprofit;
        
    }
};