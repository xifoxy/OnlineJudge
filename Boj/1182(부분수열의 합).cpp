#include <bits/stdc++.h>
using namespace std;
int n[21], N, S, sum, cnt;
void dfs(int cur = 0) {
	if(cur == N) return;
	if(sum + n[cur] == S) cnt++;
	dfs(cur + 1); sum += n[cur];
	dfs(cur + 1); sum -= n[cur];
}
int main() {
	scanf("%d%d", &N, &S);
	for(int i = 0; i < N; ++i)
		scanf("%d", n + i);
	dfs(0);
	printf("%d\n", cnt);
}

//설명
//부분수열이다 그냥 완탐으로 돌리면 된다.