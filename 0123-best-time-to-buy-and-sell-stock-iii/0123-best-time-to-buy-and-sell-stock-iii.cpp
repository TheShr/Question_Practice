class Solution {
public:

    int func(int idx, vector<int> &prices, int buy, int cap, vector<vector<vector<int>>> &dp){
        if(idx == prices.size()) return 0;
        if(cap < 0) return 0;
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        int ans = 0;
        if(buy == 0) ans = max(-prices[idx] + func(idx+1, prices, 1, cap-1, dp), func(idx+1, prices, 0, cap, dp));
        else ans = max(prices[idx] + func(idx+1, prices, 0, cap, dp), func(idx+1, prices, 1, cap, dp));

        return dp[idx][buy][cap] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return func(0, prices, 0, 2, dp);
    }
};


/*
find all possible max to transaction 


*/