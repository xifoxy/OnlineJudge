#include <bits/stdc++.h>
using namespace std;
int n, m, a[10001];
long long r = 10000000000, ans, mid, l, cnt;
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	while(l < r) {
		mid = (l + r) / 2;
		cnt = 0;
		for(int i = 0; i < n; ++i)
			cnt += (a[i] / mid);
		if(m <= cnt) {
			l = mid + 1;
			ans = max(ans, mid);
		} else r = mid;
	}
	cout << ans << '\n';
}


// 설명
// 생각보다 쉬운문제다.
// 이분 탐색으로 풀면되는데 left와 right의 범위를 잘 잡아줘야한다.
// 문제만 보고 right의 값을 intmax값으로 잡아줘서 세번 틀렸다.
// 기준값이 1억이라도 최소 10배는 크게 잡아주는게 정신건강에 좋다.
// 반복문 속에 조건은
// l + 1 < r, l = mid나 l < r, l = m + 1이나 똑같다.