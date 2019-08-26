#include <bits/stdc++.h>
using namespace std;
int n, a[1001], d[1001], ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i], d[i] = a[i];

	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(a[i] < a[j]) {
				d[j] = max(d[i] + a[j], d[j]);
			}
		}
	}

	for(int i = 0; i < n; ++i)
		ans = max(d[i], ans);

	cout << ans << '\n';
}

//설명
//가장 긴 증가하는 부분수열과 로직은 같다.
//단, 메모이제이션 할때 max값 갱신하는방법이 조금 다르다.
//기준점의 D[i] + A[j]값이 D[j]값보다 클때 갱신하면 된다.