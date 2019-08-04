#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 1;
int dp[M], pre[M], S, E;
void print(int cur) {
	if(cur == S) {
		printf("%d ", cur);
		return;
	}
	print(pre[cur]);
	printf("%d ", cur);
}
bool safe(int x, int cur) {
	return x >= 0 && x < M && (!d[x] || dp[x] > dp[cur] + 1);
}
int main() {
	scanf("%d%d", &S, &E);
	queue<int> Q;
	Q.push(S);
	dp[S] = 1;
	while(!Q.empty()) {
		int pos = Q.front();
		Q.pop();
		if(pos == E) break;
		if(safe(pos * 2, pos)) {
			dp[pos * 2] = dp[pos] + 1;
			pre[pos * 2] = pos;
			Q.push(pos * 2);
		}
		if(safe(pos + 1, pos)) {
			dp[pos + 1] = dp[pos] + 1;
			pre[pos + 1] = pos;
			Q.push(pos + 1);
		}
		if(saef(pos - 1, pos)) {
			dp[pos - 1] = dp[pos] + 1;
			pre[pos - 1] = pos;
			Q.push(pos - 1);
		}
	}
	printf("%d\n", dp[E] - 1);
	print(E);
	puts("");
}

// 설명(BFS, PREV배열)
// 1. 그리디한 솔루션이다. 중복 방문과 이동 카운트를 
// 최소화 하기 위해 메모이제이션을 이용한다.
// 2. 메모이제이션에 최소값이 갱신될때마다 prev배열에 
// 현재 다음 위치에 현재 위치를 집넣는다.
// 3. prev를 출력하는 최악의 시간복잡도는 O(N)이다. 
// 1e5 밖에 안되기 때문에 재귀 함수를 돌려준다. prev배열 뒤집기도 귀찮고(..) 