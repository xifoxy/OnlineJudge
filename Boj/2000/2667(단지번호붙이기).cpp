#include <bits/stdc++.h>
using namespace std;
int d[25][25], n;
bool vsit[25][25];
int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}
int dfs(int x, int y) {
	int c = 0;
	if(!safe(x, y) || vsit[x][y] || !d[x][y]) return 0;
	vsit[x][y] = true;
	c++;
	c += dfs(x + 1, y);
	c += dfs(x - 1, y);
	c += dfs(x, y + 1);
	c += dfs(x, y - 1);
	return c;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%1d", &d[i][j]);

	vector<int> vec;
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(d[i][j] && !vsit[i][j]) {
				vec.push_back(dfs(i, j));
				cnt++;
			}
		}
	}
	sort(vec.begin(), vec.end());
	printf("%d\n", cnt);
	for(int i = 0; i < vec.size(); ++i) {
		printf("%d\n", vec[i]);
	}
}

//»ý·«