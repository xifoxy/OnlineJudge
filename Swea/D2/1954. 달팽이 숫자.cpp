#include <bits/stdc++.h>
using namespace std;
int dx[]{0,1,0,-1}, dy[]{1,0,-1,0};
int nx, ny, num, tc, n, idx;
int d[12][12];
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}
int main() {
	cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		memset(d, 0, sizeof(d));
		ny = nx = idx = num = 0;
		cin >> n;
		while(!d[nx][ny]) {
			if(safe(nx, ny)) {
				d[nx][ny] = ++num;
			}
			if(safe(nx + dx[idx], ny + dy[idx])) {
				if(d[nx + dx[idx]][ny + dy[idx]])
					idx = idx + 1 == 4 ? 0 : idx + 1;
			} else idx = idx + 1 == 4 ? 0 : idx + 1;
			nx += dx[idx];
			ny += dy[idx];
		}
		cout << '#' << i << '\n';
		for(int x = 0; x < n; ++x) {
			for(int y = 0; y < n; ++y)
				cout << d[x][y] << ' ';
			cout << '\n';
		}
	}
}

//ºù±Ûºù±Û