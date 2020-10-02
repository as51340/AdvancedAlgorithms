#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

long long my_sort(tuple<long long,long long,long long> tup1, tuple<long long, long long,long long> tup2) {
	if(get<2>(tup1) > get<2>(tup2))
		return 1;
	return 0;
}

long long find(long long x, long long link[]) {
	while(x != link[x] )
		x = link[x];
	return x;
}


bool same(long long a, long long b, long long link[]) {
	return find(a, link) == find(b, link) ;
}

void unite(long long a, long long b, long long size[], long long link[]) {
	a = find(a ,link);
	b = find(b, link);
	if(size[a] < size[b]) {
		long long tmp = a;
		a = b;
		b = tmp;
	}
	size[a ] += size[b ] ;
	link[b ] = a;
	
}




int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n,m;
	cin >> n >> m;
	long long sum_total = 0;
	vector<tuple<long long, long long,long long>> ceste;
	for (long long i = 0; i < m; i++) {
		long long x, y, z;
		cin >> x >> y >> z;
		ceste.push_back({x,y,z});
		sum_total += z;
	}
	
	sort(ceste.begin(), ceste.end(), my_sort);
	
	/*for (long long i = 0; i < m; i++) {
		cout << get<0>(ceste[i]) << " " << get<1>(ceste[i]) << " " << get<2>(ceste[i]) << endl;
	}*/
	
	
	
	
	
	long long link[n+1];
	long long size[n+1];
	for (long long i = 1; i <= n; i++) {
		link[i] = i;
		size[i] = 1;
	}
	
	long long cesta = 0;
	long long sum = 0;
	
	
	 
	while(cesta < m) {
		long long cijena = get<2>(ceste[cesta]);
		long long vrh1 = get<0>(ceste[cesta]);
		long long vrh2 = get<1>(ceste[cesta]);
		if(!same(vrh1, vrh2, link)) {
			unite(vrh1, vrh2, size, link);
			//cout << "Povezat cu " << vrh1 << " i " << vrh2 << endl;
			sum += cijena;
		}
		cesta++;
	}
	
	
	cout << sum_total - sum;
	
	
	
	
	
	
	
	
	return 0;
}
	
	
