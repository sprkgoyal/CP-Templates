const int N = 200005;
int timer = 0, lgn;
vector<int> adj[N], tin(N), tout(N), lev(N, 0);
vector<vector<int>> up;

void dfs(int v, int p) {
	lev[v] = lev[p]+1;
	tin[v] = timer++;
	up[v][0] = p;
	for(int i=1; i<=lgn; i++)
		up[v][i] = up[up[v][i-1]][i-1];
	for(int u: adj[v])
		if(u != p)
			dfs(u, v);
	tout[v] = timer++;
}

bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int u, int v) {
	if(is_ancestor(u, v))
		return u;
	if(is_ancestor(v, u))
		return v;
	for(int i = lgn; i >= 0; i--)
		if(not is_ancestor(up[u][i], v))
			u = up[u][i];
	return up[u][0];
}

void preprocess(int root, int n) {
	lgn = ceil(log2(n));
	up.assign(n+1, vector<int>(lgn+1, 0));
	dfs(root, root);
}
