#include<bits/stdc++.h>
 
using namespace std;
 
 
void computePow(vector<long long> &pows, int k, long long a, long long b) {
	pows[0]= 1;
	for(long long i = 1; i < k; i++) {
		pows[i] = (pows[i-1] * a) % b;
	}
}
 
long long hash2(string s, long long a, long long b,vector<long long> &pows) {
	long long powp = 1;
	int n = s.size();
	long long value = 0;
	for(int i = n-1; i >= 0; i--) {
		int num = s[i];
		value = (value + (num * pows[n-1-i])) % b;
 
	}
	return value;
}
 
void computeHashSubstring(string s, vector<long long> &arr, int k, long long a, long long b) {
	arr[0]= s[0];
	for(int i = 1; i < s.size(); i++) {
		arr[i]= (arr[i-1] * a + s[i]) % b;
	}
}
 
int index(vector<long long> &pows, string s, string sample, vector<long long> &arr, long long a1, long long b1, long long hash_sample) {
		int n = s.size();
		long long a, b;
		for(int i = 0; i < n; i++) {
			a = i;
			b = a + sample.size() -1;
			long long hash_substring;
			if(b >= n)
				break;
				
			if(a == 0) {
				hash_substring = arr[b];
			}
			else {
				hash_substring = (arr[b] - (arr[a-1]*pows[b-a +1])) % b1;
				hash_substring = (hash_substring + b1) % b1;
			}
			if(hash_substring == hash_sample) {
				return a;
			}
		}
		return -1;
}
		
	
int main(void) {
	string sample;
	getline(cin,sample);
	vector<long long> pows(400005, 0);
	int n;
	scanf("%d", &n);
	cin.ignore();
	long long a1, b1, a2,b2;
	a1 = 31;
	b1 = 1e9 + 9;
	a2 = 911382323;
	b2 = 972663749;
	computePow(pows, 400005 ,a1,b1);
	long long hash_sample = hash2(sample, a1, b1,pows);
	for(int i = 0; i < n; i++) {
		string s;
		getline(cin,s);
		if(s.size() < sample.size()) {
			cout << -1 << endl;
			continue;
		}
		vector<long long> arr(s.size(),0);
		computeHashSubstring(s,arr, s.size() -1, a1,b1);
		printf("%d\n", index(pows, s,sample, arr,a1,b1,hash_sample));
	}
	return 0;
}