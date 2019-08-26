#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 1;
int dp[M], st, ed;
bool safe(int x, int cur) {
	return x >= 0 && x < M && (!d[x] || dp[x] > dp[cur] + 1);
}
int main() {
	scanf("%d%d", &st, &ed);

	queue<int> Q;
	Q.push(st);
	dp[st] = 1;
	while(!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		if(cur * 2 < M && (!dp[cur * 2] || dp[cur * 2] > dp[cur])) {
			dp[cur * 2] = dp[cur];
			Q.push(cur * 2);
		}

		if(safe(cur, cur + 1)) {
			dp[cur + 1] = dp[cur] + 1;
			Q.push(cur + 1);
		}

		if(safe(cur, cur - 1)) {
			dp[cur - 1] = dp[cur] + 1;
			Q.push(cur - 1);
		}
	}
	printf("%d\n", dp[ed] - 1);
}

// 설명(BFS)
// 1. 그리디한 솔루션이다. 중복 방문과 이동 카운트를 
// 최소화 하기 위해 메모이제이션을 이용한다.

// 문제 설명대로 구현하면 된다.
// +1과 -1은 이동카운트 추가
// *2는 유지