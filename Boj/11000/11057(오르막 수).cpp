#include <bits/stdc++.h>
using namespace std;
int d[1001][10], n;
int main() {
	cin >> n;
	for(int i = 0; i <= 9; ++i)
		d[1][i] = 1, d[1][0] += d[1][i];
	d[1][0]--;

	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j <= 9; ++j) {
			for(int k = j; k <= 9; ++k)
				d[i][j] = (d[i][j] + d[i - 1][k]) % 10007;
		}
		for(int k = 1; k <= 9; ++k)
			d[i][0] = (d[i][0] + d[i][k]) % 10007;
	}
	int ans = 0;
	for(int i = 0; i <= n; ++i) {
		ans = (ans + d[i][0]) % 10007;
	}
	cout << ans << '\n';
}

#include <cstdio>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
int n, d[1000][10], ans;
int main() {
	scanf("%d", &n);
	REP(i, 10) d[0][i] = 1;
	FOR(i, 1, n + 1) {
		REP(j, 10) {
			FOR(k, 0, j + 1) {
				d[i][k] = (d[i][k] + d[i - 1][j]) % 10007;
			}
		}
	}
	REP(i, 10) ans = (ans + d[n - 1][i]) % 10007;
	printf("%d\n", ans);
}

//설명
//규칙을 보는법이 필요하다.
//일단 한자리 숫자는 무조건 오르막 수
//문제에서 제시하듯 동일한 숫자로 구성된 숫자도 오르막수로 친다.
//그럼 두자리로 된 숫자의 오르막수는?
//1 = 11~19
//2 = 22~29
//3 = 33~39
//...
//9 = 99
//세자리 숫자도 마찬가지다
//1 = 100 + ([11~19] ~ 99)
//2 = 200 + ([22~29] ~ 99)
//...
//9 = 999
//여기서 규칙을 띄게 되는데 잘 살펴보면
//N자리는 N-1자리의 첫째 자리 수들이 크거나 같은 수들의 합이다.
//그러니까.. D[N][자릿수] = D[N-1][자릿수] ~ [D][N-1][9] 까지의 합을 구하면 된다.
//과거에는 더 깔끔하게 푼것 같다.