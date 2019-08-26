#include <bits/stdc++.h>
using namespace std;
const int MX = 10;
int a[MX][MX], n, ans = 100000000;
bool visited[MX];
void tsp(int pos, int cost, int visit, int start) {
	if(visit == 1) {
		if(a[pos][start]) {
			ans = min(cost + a[pos][start], ans);
		}
		return;
	}
	for(int i = 0; i < n; ++i) {
		if(!visited[i] && a[pos][i] && i != start) {
			cost += a[pos][i];
			visited[i] = true;
			tsp(i, cost, visit - 1, start);
			cost -= a[pos][i];
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < n; ++i) {
		tsp(i, 0, n, i);
	}
	printf("%d\n", ans);
}

//설명
//범위가 10이다. 이보다 커지면 완탐으로 풀릴수가 없는 경우가 많다.
//그때는 최단거리 알고리즘 중에 하나를 선택해야한다.
//문제에서의 조건이 출발도시가 정해지지 않았기 때문에 모든 경우를 다 탐색해야한다.
//0이면 방문이 불가하다는 기저사례를 확인해야하고, 출발했던 도시를 다시 돌아가야 하기 때문에
//몇가지 조건문이 필요하니 반보문 내부에 조건과 방문해야할 도시가 N - 1개가 되었을때를 잘 살펴보자.