#include <bits/stdc++.h>
using namespace std;
int n;
struct P {
	int x, y;
};
P d[100001];
bool cmp(const struct P &u, const struct P &v) {
	if(u.y == v.y) return u.x < v.x;
	return u.y < v.y;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> d[i].x >> d[i].y;

	stable_sort(d, d + n, cmp);
	for(int i = 0; i < n; ++i)
		cout << d[i].x << ' ' << d[i].y << '\n';
}

//»ý·«