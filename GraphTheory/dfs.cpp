#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<int> graf[], int el, bool visited[],int distances[]) {
	//cout << "Usao sam u dfs i pregledavam graf za el = " << el << endl;
	if(visited[el -1])
		return;
	visited[el-1] = true;
	for(auto u: graf[el -1]) {
		dfs(graf,u,visited, distances);
		distances[el-1] = max(distances[el-1], 1 + distances[u -1]);
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int n, m;
	cin >> n >> m;
	vector<int> graf[n];
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graf[x-1].push_back(y);
		
	}
	
	
	bool visited[n];
	int distances[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;	
		distances[i] = 0;
	}

	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if(!visited[i])
			dfs(graf, i, visited, distances);
	}
	
	int max = 0;
	for (auto u: distances) {
		if(u > max)
			max = u;
	}
	
	cout << max +1  	;
	

	return 0;
}
	