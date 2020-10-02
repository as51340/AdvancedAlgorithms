#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<math.h>

using namespace std;

typedef long long ll;

struct Point {
	double x,y;
};

vector<Point> tocke;
Point p;
double x;

double distance(Point a, Point b) {
	return sqrt((double)(b.x-a.x) * (double)(b.x-a.x) + (double)(b.y -a.y)*(double)(b.y -a.y));
}

Point next(stack<Point> &stog) {
	Point to = stog.top();
	stog.pop();
	Point res = stog.top();
	stog.push(to);
	return res;
}


int sgn(double x) {
	if(x == 0)
		return 0;
	if(x > 0)
		return 1;
	return -1;
}

int ccw(Point a, Point b, Point c) {
	double w = (a.x) *(b.y - c.y) + (b.x)* (c.y -a.y) + (c.x) * (a.y - b.y);
	return sgn(w);
}

bool cmp(Point p1, Point p2) {
	int o = ccw(p,p1, p2);
	if(o == 0) {
		return distance(p,p1) >= distance(p,p2)? false: true;
	}
	return o == 1;
}

int solve(int n) {
	double min = 2000000.5;
	int min_index = -1;
	for(int i = 0; i < n; i++) {
		if(tocke[i].y < min) {
			min = tocke[i].y;
			min_index = i;
		} else if(fabs(tocke[i].y - min) < 1e-9) {
			if(tocke[i].x < tocke[min_index].x) {
				min_index = i;
			}
		}
	}
	
	Point temp = tocke[0];
	tocke[0] = tocke[min_index];
	tocke[min_index] = temp;
	stack<Point> stog;
	p = tocke[0];	
	sort(tocke.begin() +1 ,tocke.end(), cmp);
	
	int m = 1; 
	for(int i = 1; i < n; i++) {
		while(i < n -1 && ccw(p,tocke[i], tocke[i+1]) == 0)
			i++;
		tocke[m] = tocke[i];
		m++;
	} 
	x += distance(tocke[0], tocke[1]);
	x += distance(tocke[1], tocke[2]);
	stog.push(tocke[0]);
	stog.push(tocke[1]);
	stog.push(tocke[2]);
	int last = -1;
	for(int i = 3; i < m; i++) {
		while(ccw(next(stog), stog.top(), tocke[i]) != 1) {
			
			Point a = next(stog);
			Point b = stog.top();
			x -= distance(a, b);
			stog.pop();

		}
		
		Point to = stog.top();
		stog.push(tocke[i]);
		last = i;
		x +=distance(to,tocke[i]);

	}
	return last;
}


int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		Point p;
		cin >> p.x >> p.y;
		tocke.push_back(p); 
	}
	int index = solve(n);
	x += distance(tocke[0], tocke[index]);
	cout << floor(x);
	return 0;
}
		