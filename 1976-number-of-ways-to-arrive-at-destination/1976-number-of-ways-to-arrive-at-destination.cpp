class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> adjLs(n);
        vector<long long> cost(n, LLONG_MAX);
        vector<int>  ways(n,0);
        int mod = (long long)(1e9+7);
        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            long long w = it[2];

            adjLs[u].push_back({v,w});
            adjLs[v].push_back({u,w});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        pq.push({0, 0});
        cost[0]= 0;
        ways[0] = 1;
        while(!pq.empty()){
            auto &it = pq.top();
            long long cst = it.first;
            int node = it.second;
            pq.pop();

            for(auto &it : adjLs[node]){
                int u = it.first;
                long long w = it.second;

                if(cost[u] > w + cst){
                    cost[u] = w + cst;
                    pq.push({cost[u], u});

                    ways[u] = ways[node];
                }
                else if(cost[u] == w + cst) ways[u] = (ways[u] + ways[node])%mod;
                
            }
        }
       return ways[n-1] % mod;
    }
};