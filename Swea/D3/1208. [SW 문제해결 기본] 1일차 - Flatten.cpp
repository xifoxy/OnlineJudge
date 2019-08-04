#include <bits/stdc++.h>
using namespace std;
int d[101], n, dump;
int main() {
	for(int tc = 1; tc <= 10; ++tc) {
		cin >> dump;
		int l = 999, r = 0;
		memset(d, 0, sizeof(d));
		for(int i = 0; i < 100; ++i) {
			cin >> n;
			d[n]++;
			l = min(l, n);
			r = max(r, n);
		}
		while(l <= r) {
			if(!dump) break;
			if(d[l] && d[r]) {
				d[l]--; d[l + 1]++;
				d[r]--; d[r - 1]++;
			}
			while(!d[l]) ++l;
			while(!d[r]) --r;
			dump--;
		}
		cout << '#' << tc << ' ';
		cout << abs(r - l) << '\n';
	}
}

//»ý·«