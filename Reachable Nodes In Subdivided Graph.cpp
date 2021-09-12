#define pii pair<int, int>

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<vector<pii>> graph(N);
        for (vector<int> edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        map<int, int> dist;
        dist[0] = 0;
        for (int i = 1; i < N; ++i)
            dist[i] = M+1;

        map<pii, int> used;
        int ans = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();
            int d = top.first, node = top.second;
            if (d > dist[node]) continue;

            ans++;

            for (auto pair: graph[node]) {
                int nei = pair.first;
                int weight = pair.second;
                used[{node, nei}] = min(weight, M - d);

                int d2 = d + weight + 1;
                if (d2 < min(dist[nei], M+1)) {
                    pq.push({d2, nei});
                    dist[nei] = d2;
                }
            }
        }

        for (vector<int> edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            ans += min(w, used[{u, v}] + used[{v, u}]);
        }
        return ans;
    }
};
