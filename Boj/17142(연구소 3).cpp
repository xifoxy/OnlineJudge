#include <bits/stdc++.h>
using namespace std;
int d[51][51], n, k, air, dx[]{1,-1,0,0}, dy[]{0,0,1,-1}, nx, ny;
int visit[51][51];
struct P {
	int x, y;
};
vector<P> virus;
P pos;
bool safe(int x, int  y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}
int flood(queue<P> &Q, int air) {
	int time = 0;
	for(; air && !Q.empty(); ++time) {
		int sz = Q.size();
		for(int i = 0; i < sz && air; ++i) {
			pos = Q.front(); Q.pop();
			for(int i = 0; i < 4; ++i) {
				nx = pos.x + dx[i];
				ny = pos.y + dy[i];
				if(safe(nx, ny) && !visit[nx][ny] && (!d[nx][ny] || d[nx][ny] == 2) && air) {
					visit[nx][ny] = true;
					air = d[nx][ny] == 2 ? air : air - 1;
					Q.push({nx,ny});
				}
			}
		}
	}
	memset(visit, false, sizeof(visit));
	return air ? 0xffff : time;
}
int sol(int cnt, vector<int> &per, int pos = 0) {
	if(cnt == 0) {
		queue<P> Q;
		for(int i = 0; i < k; ++i) {
			Q.push(virus[per[i]]);
		}
		return flood(Q, air);
	}
	int ret = 0xffff;
	for(int i = pos; i < virus.size(); ++i) {
		per.push_back(i);
		ret = min(ret, sol(cnt - 1, per, i + 1));
		per.pop_back();
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d", &d[i][j]);
			if(d[i][j] == 2)
				virus.push_back({i,j});
			else if(!d[i][j])
				air++;
		}
	}
	vector<int> next_per;
	next_per.reserve(virus.size());
	int ans = sol(k, next_per);
	if(!air) puts("0");
	else printf("%d\n", ans == 0xffff ? -1 : ans);
}

//설명
//일단 문제는 연구소 문제를 풀었으면 이것또한 쉽게 풀 수 있다.
//대게 이런 몇초가 걸리냐? 이런 문제들은 난 대부분 queue사이즈만큼 포문을 돌리는걸 선호한다.
//활성화 되지 않은 바이러스는 공기처럼 취급된다는걸 너무 늦게봐서 두번이나 틀렸다