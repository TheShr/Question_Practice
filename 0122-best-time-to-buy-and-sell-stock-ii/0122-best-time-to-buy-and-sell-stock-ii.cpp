class Solution {
public:
    int func(int i, vector<int> &prices, int buy, vector<vector<int>> &dp){
        if(i == prices.size()) return 0; 
        if(dp[i][buy] != -1) return dp[i][buy];
        int ans = 0;
        if(buy == 0) ans = max(-prices[i] + func(i+1, prices, 1, dp), func(i+1, prices, 0, dp));   
        else ans = max(prices[i] + func(i+1, prices, 0, dp), func(i+1, prices, 1, dp));

        return dp[i][buy] = ans;
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return func(0, prices, 0, dp);
    }
};