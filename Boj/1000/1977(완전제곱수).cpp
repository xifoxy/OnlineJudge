#include <bits/stdc++.h>
using namespace std;
int a, b, l, sum, mn = 1e6;
int main() {
	cin >> a >> b;
	l = sqrt(a);
	if(l * l < a) ++l;
	for(int i = l; i * i <= b; ++i) {
		mn = min(mn, i * i);
		sum += (i * i);
	}
	if(!sum) cout << -1;
	else cout << sum << '\n' << mn;
}

//»ý·«