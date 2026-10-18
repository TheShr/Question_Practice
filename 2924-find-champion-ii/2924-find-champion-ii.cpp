class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
       
        vector<int> in(n);
        vector<vector<int>> adjls(n);
        

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];

            in[v]++;
           
        }
        int node = 0, cnt = 0;
        for(int i = 0 ; i<n; i++){
            if(in[i] == 0){
                node = i;
                cnt++;
            }
        }

        if(cnt > 1) return -1;
        else return node;

        
    }
};
