class Solution {
public:
    int func(int idx, vector<int> &dp){
        if(idx == 0) return 1;
        if(idx == 1) return 1;

        if(dp[idx] != -1) return dp[idx];
        dp[idx] = func(idx-1, dp) + func(idx-2, dp);
        return dp[idx];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return func(n , dp);
    }
};