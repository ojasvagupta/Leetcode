class Solution {
public:
void numbers(vector<int>& coins, int amount,int temp,int& count,vector<int> & DP)
{
    if(DP[amount]<=temp)
    {
        return;
    }
    if(amount<0)
    {
        return;
    }
    if(amount==0)
    {
        count=min(count,temp);
        return;
    }
    temp++;
    for(int i=coins.size()-1;i>=0;i--)
    {
        if(coins[i]<=amount)
        {
            
            int tempamount=amount-coins[i];
            numbers(coins,tempamount,temp,count,DP);
        }
    }
    temp--;
    if(DP[amount]>temp)
    {
        DP[amount]=temp;
    }
    
}
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int count=INT_MAX;
        vector<int> DP(amount+1,INT_MAX);
        numbers(coins,amount,0,count,DP);
        if(count==INT_MAX)
        {
            return -1;
        }
        return count;
        
    }
};