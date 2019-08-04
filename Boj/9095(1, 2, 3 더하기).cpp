#include <bits/stdc++.h>
using namespace std;
int d[12], tc, num;
int a[]{1,2,3};
void sol(int n, int sum) {
	if(n >= sum) d[sum]++;
	if(sum >= n) return;
	for(int i = 0; i < 3; ++i) {
		sum += a[i];
		sol(n, sum);
		sum -= a[i];
	}
}

int main() {
	sol(11, 0);
	cin >> tc;
	for(int i = 0; i < tc; ++i) {
		cin >> num;
		cout << d[num] << '\n';
	}
}

#include <cstdio>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
int n, d[11], t;
int main() {
	d[0] = d[1] = 1; d[2] = 2;
	FOR(i, 3, 11) d[i] = d[i - 3] + d[i - 2] + d[i - 1];
	scanf("%d", &t); while(t--) printf("%d\n", scanf("%d", &n) * d[n]);
}

//설명
//과거엔 공식을 찾아보고 구현했었다.
//정해는 공식을 보도록 하고
//우선 조합의 수가 몇개 안된다.
//주어진 수는 총 1,2,3개로 만들 수 있는 1~11의 조합이다.
//그래서 그냥 완탐으로 풀었다.