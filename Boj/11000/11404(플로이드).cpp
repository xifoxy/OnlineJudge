#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 1e2 + 1, INF = 1e9;
int main() {
	int n, m, dist[MAX_V][MAX_V];
	scanf("%d%d", &n, &m);
	fill(&dist[0][0], &dist[MAX_V - 1][MAX_V - 1], INF);
	for(int i = 0; i < n; ++i) dist[i][i] = 0;

	for(int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		dist[u - 1][v - 1] = min(dist[u - 1][v - 1], w);
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < n; ++k) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			printf("%d ", dist[i][j] == INF ? 0 : dist[i][j]);
		puts("");
	}
}
 
//대망의 플로이드로 넘어왔다.
//플로이드 워셜은 DP형태의 최단경로 알고리즘이다.
//생긴 모형은 벨만포드?와 유사하게 보이니 구조 자체를 익히기에는 크게 문제가 없다.
//초기에 정의되었던 플로이드 워셜은 3차원 배열에 박아넣는거였는데
//속도는 같으나 공간복잡도가 너무 구데기다.(이부분은 종만북을 사펴보자 or kks227)
//속도적인 측면에선 본다면
//간선의 수가 V^2 보다 많이 작다면 다익스트라가 우위지만 음의가중치를 구할 수 없다는게 아쉬운 점이고
//벨만포드는 모든 정점에 대해 돌리면 O(V^2*E)이니 플로이드워셜이 무조건적으로 우위에 있다.
//모든 정점간의 거리를 빠르게 구하려면 무조건 플로이드다.
