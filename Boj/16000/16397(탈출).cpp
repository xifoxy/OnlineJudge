#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
int dp[M], N, T, G;
int main() {
	queue<int> Q;
	scanf("%d%d%d", &N, &T, &G);
	Q.push(N);
	dp[N] = 1;
	while(!Q.empty() && !dp[G]) {
		int t = Q.front(), BiG = 1;
		Q.pop();
		if(dp[t] > T) continue;
		if(t + 1 < M && !dp[t + 1]) {
			Q.push(t + 1);
			dp[t + 1] = dp[t] + 1;
		}

		while(BiG <= t * 2) BiG *= 10;
		if(t * 2 < M) {
			int multiple = t * 2 - BiG / 10;
			if(!dp[multiple]) {
				dp[multiple] = dp[t] + 1;
				Q.push(multiple);
			}
		}
	}
	if(dp[G] == 0) puts("ANG");
	else printf("%d\n", dp[G] - 1);
}


//설명(BFS)
// 1. 메모이제이션을 이용하지 않으면 중복 탐색이 지수적으로 증가한다.
// 2. 나머지는 주어진 조건으로 구현만 해주면 된다. 
// 감소하는 버튼이 없기때문에 해당 숫자의 방문여부만 저장하면 된다.
