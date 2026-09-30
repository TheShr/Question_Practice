class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> mat(n+1, vector<int> (n+1, INT_MAX));

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(i == j) mat[i][j] = 0;
            }
        }
        for(auto &it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            mat[u][v] = w;
        }

        for(int via = 1; via <= n; via++){
            for(int i = 1; i<=n; i++){
                for(int j = 1; j<=n; j++){
                    if(mat[i][via] != INT_MAX && mat[via][j] != INT_MAX) mat[i][j] = min(mat[i][j] , mat[i][via] + mat[via][j]);
                }
            }
        }
        int ans= INT_MIN;
        for(int i = 1; i<=n; i++){
            if(mat[k][i] == INT_MAX) return -1;
            ans = max(ans,mat[k][i]);
            
        }

        return ans;
    }
};