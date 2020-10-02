#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<stdio.h>
#include<math.h>

using namespace std;

void bfs(vector<int> graf[], vector<int> &outdegree,vector<int> &indegree, double probab[], int &r, int &n) {
	queue<int> q;
	
	for(int i = 1; i<=n; i++) {
		if(indegree[i] == 0)
			q.push(i);
	}
	
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		for(auto v: graf[node]) {
			probab[v] += (double)probab[node] *(1.0 / outdegree[node]);
			if(--indegree[v] == 0)
				q.push(v);
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m,r;
	cin >> n >> m >> r;
	vector<int> graf[n+1];
	vector<int> indegree(n+1, 0);
	vector<int> outdegree(n+1, 0);
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graf[a].push_back(b);
		outdegree[a]++;
		indegree[b]++;
	}
	double probab[n+1];
	for(int i = 0; i <= n; i++)
		probab[i] = 0.0;
	probab[r] = 1.0;
	bfs(graf, outdegree, indegree, probab, r,n);
	
	double maxi = -1;
	for(int i = 1; i <= n; i++) {
		if(outdegree[i] == 0 && maxi < probab[i])
			maxi = probab[i];
	}
		
	for(int i = 1; i <= n; i++) {
		if(outdegree[i] == 0 && fabs(probab[i] - maxi) <= 1e-9)
			cout << i << " ";
	}
	return 0;
}
	
	
	
	
	
