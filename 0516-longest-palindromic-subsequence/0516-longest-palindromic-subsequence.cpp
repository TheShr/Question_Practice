class Solution {
public:
    int func(int i, int j, string str1, string str2, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(str1[i] == str2[j]) ans = 1 + func(i-1, j-1, str1, str2, dp);
        else ans = max(func(i-1, j, str1, str2, dp), func(i, j-1, str1, str2, dp));


        return dp[i][j] = ans;
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(),s1.end());
        vector<int> prev(n+1, 0), curr(n+1, 0);

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                int ans = 0;
                if(s[i-1] == s1[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
                
            }
            prev = curr;
        }
        return prev[n];
    }
};