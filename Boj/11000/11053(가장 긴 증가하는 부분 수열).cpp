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

	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
			if(a[i] < a[j])
				d[j] = max(d[i] + 1, d[j]);

	for(int i = 0; i < n; ++i)
		ans = max(d[i], ans);

	cout << ans << '\n';
}

//설명
//증가수열, 감소수열 범위가 작은선에선 O(N^2)이다.
//투포인터는 아니지만 포인터를 두개 이용한다고 생각하면 된다.
//D[X]부터 D[N]까지 돌면서 D[X]보다 큰 숫자가 존재한다면
//그 위치를 갱신해주면 된다.
//만약 큰 숫자를 만난다면?
//max(D[X] + 1, D[Y])가 최적값이다.
