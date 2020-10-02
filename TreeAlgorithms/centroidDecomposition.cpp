#include<iostream>
#include<vector>

using namespace std;

//visited mi je za to da li je to vec bija centroid
long long x = 0;

void dfs(int u, int par, vector<int> tree[], vector<int> &subtree,vector<bool> &visited) {
	subtree[u] = 1;
	for(auto v: tree[u]) {
		if(par == v || visited[v] == true) {
			continue;
		}
		dfs(v,u,tree,subtree,visited);
		subtree[u]+=subtree[v];
	}
}

int findcen(int u, int p,int size, vector<int> tree[], vector<int> &subtree,vector<bool> &visited) {
	for(auto v: tree[u]) {
		if(p == v || visited[v] == true) {
			continue;
		}
		if(subtree[v] * 2 > size)
			return findcen(v,u,size,tree,subtree,visited);
	}
	return u;
}

void my_dfs(int u, int p, int k,int depth,vector<bool> &visited, vector<int> &cnt, bool flag,vector<int> tree[]) {
	if(flag == true) 
		cnt[depth]++;
	else if(k - depth < cnt.size() && k - depth >= 0) {
		x+= cnt[k - depth];
	}
	for(auto v: tree[u]) {
		if(v == p || visited[v]) {
			continue;
		}
		my_dfs(v,u,k,depth +1,visited,cnt,flag,tree);
	}
}

void solve(int u, int p,int k, vector<int> &subtree, vector<int> tree[], vector<bool> &visited) {
	u = findcen(u,p,subtree[u],tree,subtree,visited);
	vector<int> cnt(subtree[u], 0);
	cnt[0] = 1;
	for(auto v: tree[u]) {
		if(visited[v])
			continue;
		my_dfs(v,u,k,1,visited,cnt,false,tree);
		my_dfs(v,u,k,1,visited,cnt, true,tree);
	}
	visited[u] = true;
	for(auto v:tree[u]) {
		if(visited[v])
			continue;
		solve(v,u,k,subtree, tree,visited);
	}
}
		
int main(void) {
	cin.tie(NULL);
	//cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> tree[n+1];
	vector<bool> visited(n+1, false);
	vector<int> subtree(n+1, 0);
	for(int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(1,0,tree,subtree,visited);
	solve(1,1,k,subtree,tree,visited);
	
	cout << x;
	return 0;
}
	
	
	
	