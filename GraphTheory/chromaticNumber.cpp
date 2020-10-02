#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

bool dfs(int u, int parent, vector<int> graf[], vector<int> array, vector<int> colors,vector<bool> visited) {
	visited[u] = true;
	for(auto color: array) {
		if(color == colors[parent])
			continue;
		for(auto v: graf[u]) {
			if(color != colors[v]) {
				colors[u] = color;
				if(!visited[v]) {
					if(!dfs(v, u, graf, array, colors, visited)) {
						colors[u] = 0;
						break;
					}
				}
			} else {
				colors[u] = 0;
				break;
			}
		}
		if(colors[u] != 0)
			return true;
		
	}
	return false;
}

int main(void) {
	string s;
	cout << "Type file name: ";
	cin >> s;
	
	ifstream file(s);
	
	if(file.is_open()) {
		int n;
		file >> n;
		vector<int> graf[n+1];
		vector<int> array;
		array.push_back(1);
		vector<int> colors(n+1, 0);
		int nula = 0;
		vector<bool> visited(n+1, false);
		for(int i = 1; i <= n; i++) {
			for(int j =1; j <= n; j++) {
				int x;
				file >> x;
				if(x == 1) {
					nula = 1;
					graf[i].push_back(j);
				}
			}
		}
		if (nula == 0) {
			cout << 1;
			return 0; 
			
		}
		int j = 2;
		bool flag = true;
		while(true) {
			array.push_back(j);
			for(int i = 1; i <= n; i++) {
				if(!visited[i]) {
					flag = dfs(i,0,graf,array,colors,visited);
					if(!flag) {
						j++;
						for(int i = 0; i <= n; i++) {
							colors[i] = 0;
							visited[i] = false;
						}
						break;
					}
				}
			}
			if(flag == true) {
				cout << j;
				break;
			}
		}
	} else {
		cout << "File reading failed";
	}	
	return 0;
}
	
					
	
		
	