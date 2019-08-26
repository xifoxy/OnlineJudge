#include <bits/stdc++.h>
using namespace std;
int n, d[1000001], b, c;
long long ans;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> d[i];

	ans = n;
	cin >> b >> c;
	for(int i = 0; i < n; ++i) {
		d[i] -= b;
		if(d[i] > 0) {
			if(d[i] % c) ans++;
			ans += (d[i] / c);
		}
	}
	cout << ans;
}

//설명
//삼성기출답지않게 정말 쉬운 문제다.
//너무 쉬우니 생략