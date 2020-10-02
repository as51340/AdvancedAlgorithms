#include<iostream>
#include<vector>
#include<stack>

using namespace std;
stack<int> stog;

void dfs(int node, vector<int> graf[], bool visited[]) {
	visited[node] = true;
	
	for(auto v: graf[node]) {
		if(!visited[v])
			dfs(v, graf, visited);
	}
	
	stog.push(node);
	
}

void dfs2(int node, vector<int> inverz[], bool visited[], int scc[], int mark) {
	visited[node] = true;
	
	for(auto v: inverz[node]) {
		if(!visited[v])
			dfs2(node, inverz, visited, scc,mark);
	}
	
	scc[node] = mark;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> graf[2*n + 1];
	vector<int> inverz[2* n + 1];
	for(int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		graf[a+ n].push_back(b);
		graf[b +n].push_back(a);
		inverz[b].push_back(a+ n);
		inverz[a].push_back(b+n);
		
	}
	
	bool visited[2*n + 1] = { false };
	
	for(int i = 1; i <= 2* n; i++) {
		if(!visited[i])
			dfs(i, graf, visited);
	}
	
	int scc[2*n +1];
	for(int i = 0; i <= 2*n; i++) {
		visited[i] = false;
	}
	int mark = 1;
	while(!stog.empty()) {
		int node = stog.top();
		stog.pop();
		if(!visited[node]) {
			dfs2(node, inverz, visited, scc, mark);
			mark++;
		}
	}

	bool flag = true;
	for(int i = 1; i <= n; i++) {
		if(scc[i] == scc[i+n]) {
			flag = false;
			break;
		}
	}
	if(n == 1)
		cout << "YES";
	else
		if(flag == true)
			cout << "YES";
		else
			cout << "NO";	
	return 0;
}
		

	
	
	
	
	
	
	
	
	
	
	
	