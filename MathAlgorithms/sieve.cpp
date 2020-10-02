#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	
	int n, a, b,k;
	scanf("%d", &n);
	int mat[n][3];
	vector<int> v;
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d", &mat[i][0], &mat[i][1], &mat[i][2]);
		v.push_back(mat[i][1]);
	}
	sort(v.rbegin(), v.rend());
	int maxn = v[0];
	int arr[maxn];
	bool sieve[maxn];
	
	for(int i = 0; i < maxn;i++) {
		arr[i] = 0;
		sieve[i] = true;
	}
	sieve[0] = false;
	for (int i = 2; i*i <= maxn; i++) {
		if(sieve[i-1] == false)
			continue;
		int j= i * 2 - 1;
		while(true) {
				sieve[j] = false;
				j += i;
				if(j >= maxn)
					break;
		}
	}
	
	int result = 0;

	for (int i = 0; i < n; i++) {
		
		int a = mat[i][0];
		result = 0;
		int b = mat[i][1];
		int k = mat[i][2];
		for (int j = a; j <= b; j++) {
			int sum = 1;
			int temp = j;
			if(arr[j-1] != 0) {
				if(arr[j-1] == k)
					result++;
				continue;
			}
			for(int k = 2; k*k <= temp; k++) {
				if(sieve[k-1] == false)
					continue;
				int count = 0;
				while(temp % k == 0) {
					count++;
					temp /= k;
				}
				sum *= count +1;
			}
			if(temp != 1)
				sum *= 2;
			arr[j-1] = sum;
			if (sum == k)
				result++;
		}
		printf("%d\n",result);
	}
	
	return 0;
}
	
	

	