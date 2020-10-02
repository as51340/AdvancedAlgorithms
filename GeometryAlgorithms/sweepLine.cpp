#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<math.h>

using namespace std;

typedef long long ll;
vector<pair<ll,int>> events;

ll solve() {
	ll max = -1;
	ll res = 0;
	ll pos = events[0].first;
	
	for(auto par: events) {
		if(par.second == 0) {
			res++;
		}
		else if(par.second == 1) {
			res--;
		}
		if(res > max) {
			max = res;
			pos = par.first;
		}
	}
	return pos;
}

int main(void) {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		events.push_back({x,0});
		ll l;
		cin >> l;
		events.push_back({x+l-1, 1});
	}
	
	sort(events.begin(), events.end());
	
	cout << solve();
	
	return 0;
}
	