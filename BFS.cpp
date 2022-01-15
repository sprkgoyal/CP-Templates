vector<bool> vis(200001, false);

void bfs(int v) {
	queue<int> q;
	vis[v] = true;
	q.push(v);
	while(not q.empty()) {
		v = q.front();
		q.pop();
		for(int u: adj[v]) {
			if (not vis[u]) {
				vis[u] = true;
				q.push(u);
			}
		}
	}
}
