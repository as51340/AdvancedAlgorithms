#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int cuts = 0;

int dfs(int u, int par, vector<int> tree[], int m, vector<int> &values) {
	vector<int> djeca;
	for(auto v: tree[u]) {
		if(v == par)
			continue;
		int child = dfs(v,u,tree,m,values);
		djeca.push_back(child);
	}
	sort(djeca.begin(), djeca.end());
	for(auto child: djeca) {
		if(values[u] + child <= m) {
			values[u] += child;
		}
		else {
			cuts++;
		}
	}
	return values[u];
}

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<int> values(n+1, 0);
	vector<int> tree[n+1];
	for(int i = 1; i <= n; i++) {
		cin >> values[i];
	}
	for(int i = 1; i <= n-1; i++) {
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	
	int x = dfs(1,0,tree,m,values);
	cout << cuts;
	return 0;
}
		
		