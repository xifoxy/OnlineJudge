#include <bits/stdc++.h>
using namespace std;
const int MX = 1000;
int d[MX + 1][MX + 1], n, m, k, cnt, idx;
int dx[]{1,0,-1,0}, dy[]{0,1,0,-1};
bool safe(int x, int y) {
	return x >= 0 & y >= 0 && x < m && y < n;
}
int main() {
	cin >> n >> m >> k;
	if(n * m < k) cout << 0;
	else {
		int nx = 0, ny = 0;
		while(!d[nx][ny]) {
			if(safe(nx, ny)) {
				d[nx][ny] = ++cnt;
				if(cnt == k) break;
			}
			if(safe(nx + dx[idx], ny + dy[idx])) {
				if(d[nx + dx[idx]][ny + dy[idx]])
					idx = idx + 1 == 4 ? 0 : idx + 1;
			} else idx = idx + 1 == 4 ? 0 : idx + 1;
			nx += dx[idx];
			ny += dy[idx];
		}
		cout << ny + 1 << ' ' << nx + 1;
	}
}


//#달팽이 숫자
//제기랄 x, y 출력할때 주의하자.