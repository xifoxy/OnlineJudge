#include <bits/stdc++.h>
using namespace std;
int n, a[1001], d[1001], ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i], d[i] = 1;

	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(a[i] > a[j]) {
				d[j] = max(d[i] + 1, d[j]);
			}
		}
	}

	for(int i = 0; i < n; ++i)
		ans = max(d[i], ans);

	cout << ans << '\n';
}

//설명
//가장 긴 증가하는 부분 수열