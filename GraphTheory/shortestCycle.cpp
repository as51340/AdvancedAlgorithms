#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<unordered_map>

using namespace std;

void dfs(int current, int parent, int sign[], int parents[], vector<int> graf[], bool visited[], long long &my_min) {
	visited[current] = true;
	
	if(sign[current] == 2)
		return;
	if(sign[current] == 1) {
		int node = parent;
		long long cnt = 1;
		
		while(node != current) {
			node = parents[node];
			cnt++;
		}
		if(my_min == -1)
			my_min = cnt;
		else
			my_min = min(my_min, cnt);
		

		return;
	}
	sign[current] = 1;
	parents[current] = parent;
	
	
	
	for(auto v: graf[current]) {
		
		if(v == parents[current])
			continue;
		
		dfs(v, current, sign, parents,  graf,visited,my_min);
	
	}
	
	sign[current] = 2;
}
	
int main(void) {
	cout << "Enter file name: ";
	string s;
	cin >> s;
	int n;
	ifstream file(s);
	if(file.is_open()) {
		file >> n;
		vector<int> graf[n+1];
		for(int i = 1;  i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				int x;
				file >> x;
				if(x == 1) {
					graf[i].push_back(j);
				}
			}
		}
		/*for(int i = 1; i <= n; i++) {
			cout << i << "     ";
			for(auto v: graf[i]) {
				cout << v << " ";
			}
			cout << endl;
		}*/	
		
		bool visited[n+1];
		for(int i = 0; i <= n; i++) 
			visited[i] = false;
		
		int node_begin = 1;
		
		vector<int> cycles;
		
		
		int sign[n+1];
		int parents[n+1];
		
		while(true) {
			for(int i = 0; i <= n; i++) {
				sign[i] = 0;
				parents[i]= 0;
				
			}
			int number = 1;
			long long num = -1;
			dfs(node_begin,0,sign, parents,  graf, visited,num);
			cycles.push_back(num);
			int next = -1;
			for(int i = 1; i <= n; i++) {
				if(visited[i] == false) {
					next = i;
					break;
				}
			}
			if(next == -1)
				break;
			node_begin = next;
		}
		sort(cycles.begin(), cycles.end());
		int index = 0;
		bool flag = false;
		while(true) {
			if(cycles[index] != -1) {
				cout <<  "Shortest cycle in graph is " << cycles[index];
				flag = true;
				break;
			}
			index++;
		}
		if(!flag)
			cout <<  "Shortest cycle in graph is 0";
		
	}
		
	else {
		cout << "File reading failed";
		
	}
	

return 0;
}
		
		
		
		
	
	