const ll INF = 9e18;
vector<pair<int, ll>> adj[200005];
vector<ll> d(200005, INF);
vector<int> p(200005, -1);

void dijkstra(int v) {
    d[v] = 0;
    set<pair<ll, int>> q;
    q.insert(make_pair(0ll, v));
    while (not q.empty()) {
        v = q.begin()->second;
        q.erase(q.begin());
        for(auto edge: adj[v]) {
            int to = edge.first;
            ll len = edge.second;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}
