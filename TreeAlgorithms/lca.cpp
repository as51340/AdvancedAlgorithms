#include<iostream>
#include<vector>
#include<math.h>


using namespace std;

void dfs(int u, int par, vector<int> tree[],vector<int> &depths, vector<vector<int>> &parents) {
	parents[u][0] = par;
	depths[u] = depths[par] + 1;
	for(auto v: tree[u]) {
		if(v != par) {
			dfs(v, u, tree, depths, parents);
		}
	}
}


int lca(int u, int v, vector<int> &depths, vector<vector<int>> &parents,int level) {
	if(depths[v] < depths[u]) {
		int temp = v;
		v = u;
		u = temp;
	}
	int raz = depths[v] - depths[u];
	
	for(int i = 0; i < level; i++) {
		if((raz >>i)&1)
			v = parents[v][i];
	}
	
	int j = level - 1;
	if(u == v)
		return u;
	while(j>=0) {
		if(parents[v][j] != parents[u][j]) {
			u = parents[u][j];
			v = parents[v][j];
		}
		j--;
	}
	return parents[u][0];
}

	
	

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, q;
	int level;
	cin >> n >> q;
	vector<int> tree[n+1];
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for(int j = 0; j < x; j++) {
			int y;
			cin >> y;
			tree[i].push_back(y);
			tree[y].push_back(i);
		}
	}
	vector<int> depths(n+1, 0);
	level = ceil(log2(n));
	vector<vector<int>> parents(n+1, vector<int>(level, 0));
	dfs(1, 0, tree, depths, parents);
	for(int i = 1; i < level; i++) {
		for(int u = 1; u <= n; u++) {
			if(parents[u][i-1] != 0) {
				parents[u][i] = parents[parents[u][i-1]][i-1];
			}
		}
	}
	for(int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		int x = lca(a, b,depths, parents, level);
		if(x == 0)
			cout << 1 << endl;
		else
			cout << x << endl;
	}

	return 0;
}
	
	
	
	
	