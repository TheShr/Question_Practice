class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // find node with no outgoing egde
        vector<int> in(n+1), out(n+1);


        
        for(auto &it : trust){
            int u = it[0];
            int v = it[1];

            in[v]++;
            out[u]++;    

        }

        for(int i = 1; i<=n; i++){
            if(in[i] == n-1 && out[i] == 0) return i;
        }

        return -1;
        

    }
};