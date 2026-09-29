class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int> (n, INT_MAX));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j) mat[i][j] = 0;
            }
        }
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            mat[u][v] = w;
            mat[v][u] = w;
        }

        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(mat[i][k] != INT_MAX && mat[k][j] != INT_MAX){
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                   
                }
            }
        }
        int maxi = INT_MAX, idx = 0;
        for(int i = 0; i<n; i++){
                int cnt = 0;
                for(int j = 0; j<n; j++){
                    if(i != j && mat[i][j] <= distanceThreshold){
                        cnt++;
                    }
                }
                if(maxi >= cnt){
                    maxi = cnt;
                    idx = i;
                }
        }return idx;

    }
};