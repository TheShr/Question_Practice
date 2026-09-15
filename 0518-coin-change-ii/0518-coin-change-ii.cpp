class Solution {
public:
    int func(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(idx == 0){
            if(coins[idx] == amount || amount % coins[idx] == 0) return 1;
            if(amount == 0) return 1;
            return 0;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int pick = 0;
        if(coins[idx] <= amount) pick = func(idx, amount - coins[idx], coins, dp);
        int notpick = func(idx-1, amount, coins, dp);

        return dp[idx][amount] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return func(n-1, amount, coins, dp);
    }
};