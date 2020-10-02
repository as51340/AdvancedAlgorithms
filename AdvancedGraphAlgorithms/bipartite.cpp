#include<iostream>
#include<queue>
#include<vector>


using namespace std;

bool bfs(vector<int> graf[], int start, bool visited[], vector<int> &color) {
	queue<int> q;
	int cnt = 1;
	q.push(start);
	color[start] = 1;
	while(!q.empty()) {
		int u = q.front();
		visited[u] = true;
		q.pop();	
		for(auto v: graf[u]) {
			if(!visited[v]) {
				q.push(v);
				if(color[u] == 1)
					color[v] = 2;
				else
					color[v]= 1;
			}
			else {
				if(color[v] == 1 && color[u] == 1 || color[u] == 2 && color[v] == 2) {
					return false;
				}
			}
		
		}
	}
	return true;
}
			
int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> graf[n+1];
	for(int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	bool visited[n+1] = { false };
	vector<int> color(n+1, 0);
	for(int i = 1; i<= n; i++) { 
		if(!visited[i]) {
			bool flag = bfs(graf,i,visited,color);
			if(!flag) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}
	
	