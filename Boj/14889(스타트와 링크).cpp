#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int d[20][20];
bool visit[20];
int dfs(int N, int pos) {
	int ret = 0xf777777;
	if(N == 0) {
		cnt++;
		int t1 = 0, t2 = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(visit[i] && visit[j]) t1 += d[i][j];
				else if(!visit[i] && !visit[j]) t2 += d[i][j];
			}
		}
		return abs(t1 - t2);
	}
	for(int i = pos; i < n; ++i) {
		visit[i] = true;
		ret = min(ret, dfs(N - 1, i + 1));
		visit[i] = false;
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &d[i][j]);
	printf("%d\n", dfs(n / 2, 0));
}

//설명
//삼성문제들은 N과 M이라는 시리즈를 먼저 선행하고 푸는게 좋다는걸 항상 생각한다.
//생략