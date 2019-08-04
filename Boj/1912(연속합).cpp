#include <bits/stdc++.h>
using namespace std;
int n, a[100001], d[100001], ans = -9999;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	for(int i = 1; i <= n; ++i) {
		d[i] = max(a[i], d[i - 1] + a[i]);
		ans = max(d[i], ans);
	}
	cout << ans << '\n';
}

//설명
//Input값에 음수가 존재하기때문에 무조건 더하면서 진행하면 답을 구할 수 없다.
//누적된 값보다 D[i-1]값보다 A[i]가 클때가 있다는걸 유의하자.