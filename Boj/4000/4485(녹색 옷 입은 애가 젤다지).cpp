#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 126, INF = 1e5;
int n;
int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
int adj[MAX_V][MAX_V];
int dist[MAX_V][MAX_V];
bool visit[MAX_V][MAX_V];
struct P {
	int x, y, cost;
};
struct cmp {
	bool operator()(const P &a, const P &b) {
		return a.cost > b.cost;
	}
};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}
int main() {
	int idx = 0;
	while(scanf("%d", &n)) {
		if(!n) break;
		fill(&dist[0][0], &dist[MAX_V - 1][MAX_V - 1], INF);
		memset(visit, false, sizeof(visit));
		memset(adj, 0, sizeof(adj));
		priority_queue<P, vector<P>, cmp> PQ;

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &adj[i][j]);

		PQ.push({0,0,adj[0][0]});
		dist[0][0] = adj[0][0];
		while(!PQ.empty()) {
			int x, y;
			do {
				x = PQ.top().x;
				y = PQ.top().y;
				PQ.pop();
			} while(!PQ.empty() && visit[x][y]);

			if(visit[x][y]) break;
			visit[x][y] = true;

			for(int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(safe(nx, ny) && dist[nx][ny] > dist[x][y] + adj[nx][ny]) {
					dist[nx][ny] = dist[x][y] + adj[nx][ny];
					PQ.push({nx,ny, dist[nx][ny]});
				}
			}
		}
		printf("Problem %d: %d\n", ++idx, dist[n - 1][n - 1]);
	}
}



//#다익스트라(Dijkstra's)

//길찾는 문제와 유사하다. 다익스트라를 공부했는데 이게 어렵다면
//BFS와 DFS문제 를 더 풀어보는걸 권장한다.