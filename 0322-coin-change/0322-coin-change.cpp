class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1,INT_MAX-1);
        memo[0]=0;
        for(int i=1; i<=amount;i++)
        {
            for(auto a : coins)
            {
                if(i-a>=0)
                {
                    memo[i]=min(memo[i],memo[i-a]+1);
                }
            }
        }
        return (memo[amount] == INT_MAX - 1) ? -1 : memo[amount];
    }
};