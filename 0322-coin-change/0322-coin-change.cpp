class Solution {
public:
    int func(int idx, int amount, vector<int>& coins, vector<vector<int>> &dp){
       
        if(idx == 0){
            if(amount % coins[0] == 0) return amount/coins[0];
            return 1e9;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int pick = INT_MAX;
        if(coins[idx] <= amount) pick = func(idx, amount-coins[idx], coins, dp) + 1;
        int notpick = func(idx-1, amount, coins, dp);

        return dp[idx][amount] = min(pick, notpick);


    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return (func(n-1, amount, coins, dp) == 1e9 ? -1 : func(n-1, amount, coins, dp));
    }
};