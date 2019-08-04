#include <bits/stdc++.h>
using namespace std;
int n, a[2][100001], d[2][100001], tc;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> tc;
	while(tc--) {
		cin >> n;
		memset(d, 0, sizeof(d));
		for(int i = 0; i < 2; ++i)
			for(int j = 1; j <= n; ++j)
				cin >> a[i][j];

		d[0][1] = a[0][1];
		d[1][1] = a[1][1];
		for(int i = 2; i <= n; ++i) {
			d[0][i] = d[1][i - 1] + a[0][i];
			d[1][i] = d[0][i - 1] + a[1][i];

			if(d[1][i] < d[0][i - 2] + a[1][i])
				d[1][i] = d[0][i - 2] + a[1][i];
			if(d[0][i] < d[1][i - 2] + a[0][i])
				d[0][i] = d[1][i - 2] + a[0][i];
		}
		cout << max(d[0][n], d[1][n]) << '\n';
	}
}

#include <cstdio>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define M (int)1e5
int d[2][M + 1], t, n;
int main() {
	scanf("%d", &t); while(t--) {
		scanf("%d", &n); REP(i, 2) REP(j, n) scanf("%d", d[i] + j + 1);
		FOR(i, 1, n + 1) {
			d[0][i] = d[1][i - 1] + d[0][i] < d[0][i - 1] ? d[0][i - 1] : d[1][i - 1] + d[0][i];
			d[1][i] = d[0][i - 1] + d[1][i] < d[1][i - 1] ? d[1][i - 1] : d[0][i - 1] + d[1][i];
		}
		printf("%d\n", d[0][n] < d[1][n] ? d[1][n] : d[0][n]);
	}
}

//설명
//풀었던 소스와 비교해봐도 크게 다르지는 않다. 
//다만 왜 저렇게 풀었었는지 이해가 당최 안간다 -0-
//일단 이건 자력을로 풀었다.
//일단 베이스 케이스로
//현재 위치와 대각선의 누적값을 더한다음
//비교군을 설정해서 비교를 해준다.
//P|P|O
//O|O|X
//이러한 예가 있다면
//X + P[0] or X + P[1] 이 비교 대상이다.