class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        // (stops, (node, weight))
        vector<vector<pair<int, int>>> adjLs(n);
        for(auto &it : flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adjLs[u].push_back({v,w});
        }
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}});
        dist[src] = 0;
        while(!q.empty()){
            auto &it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int d = it.second.second;
            q.pop();
            if(stops > k) break;
            for(auto &it : adjLs[node]){
                int u = it.first;
                int w = it.second;

                if(dist[u] > d + w && stops <= k){
                    dist[u] = d + w;

                    q.push({stops+1, {u, dist[u]}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};