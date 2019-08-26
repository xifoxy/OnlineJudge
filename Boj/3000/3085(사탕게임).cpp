#include <bits/stdc++.h>
using namespace std;
int n;
string bom[51];
int dx[]{1,0};
int dy[]{0,1};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}
int getMax() {
	int ret = 0, col, row;
	for(int i = 0; i < n - 1; i++) {
		col = row = 1;
		for(int j = 0; j < n - 1; j++) {
			row++, col++;
			if(bom[i][j] != bom[i][j + 1])
				row = 1;
			if(bom[j][i] != bom[j + 1][i])
				col = 1;
			ret = max(ret, max(col, row));
		}
	}
	return ret;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> bom[i];
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int z = 0; z < 2; ++z) {
				int nx = dx[z] + i;
				int ny = dy[z] + j;
				if(safe(nx, ny)) {
					swap(bom[i][j], bom[nx][ny]);
					ans = max(ans, getMax());
					swap(bom[i][j], bom[nx][ny]);
				}
			}
		}
	}
	cout << ans;
}