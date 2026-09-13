class Solution {
public:
    int func(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        int n = triangle.size();
        if(i == n-1) return triangle[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        return dp[i][j] = triangle[i][j] + min(func(i+1, j, triangle, dp), func(i+1, j+1, triangle, dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for(int i = 0; i<n; i++){
            dp[i] = vector<int> (triangle[i].size(), INT_MAX);
        }
        return func(0, 0, triangle, dp);
    }
};