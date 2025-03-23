class Solution {
public:
    const int MOD = 1e9 + 7;

int countPaths(int n, vector<vector<int>>& roads) {
    // Step 1: Build the graph
    vector<vector<pair<int, int>>> graph(n);  // node -> (neighbor, time)
    for (auto& road : roads) {
        int u = road[0], v = road[1], time = road[2];
        graph[u].emplace_back(v, time);
        graph[v].emplace_back(u, time);
    }

    // Step 2: Initialize distance and ways arrays
    vector<long long> dist(n, LLONG_MAX);
    vector<int> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;

    // Step 3: Min-heap priority queue (time, node)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [time, node] = pq.top();
        pq.pop();

        if (time > dist[node]) continue;

        for (auto& [nei, t] : graph[node]) {
            long long new_time = time + t;

            if (new_time < dist[nei]) {
                dist[nei] = new_time;
                ways[nei] = ways[node];
                pq.push({new_time, nei});
            } else if (new_time == dist[nei]) {
                ways[nei] = (ways[nei] + ways[node]) % MOD;
            }
        }
    }

    return ways[n - 1];
}
};