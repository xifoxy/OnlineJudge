#include <bits/stdc++.h>
using namespace std;
int y6, m6, n, call_time;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> call_time;
		y6 += (call_time / 30 * 10 + 10);
		m6 += (call_time / 60 * 15 + 15);
	}
	if(y6 > m6) cout << "M " << m6;
	else if(y6 < m6) cout << "Y " << y6;
	else cout << "Y M " << m6;
}

// 그냥 수학