#include <bits/stdc++.h>
using namespace std;
int board[21][21], n, m;
int dir[4][2][2]{
	{{1,0},{0,1}},
	{{0,1},{1,1}},
	{{1,1},{0,1}},
	{{1,1},{0,-1}}};
bool safe(int x, int y, int reaction) {
	return x >= 0 && y >= 0 && x < n && y < m && board[x][y] == reaction;
}
bool f(int x, int y, int type, int action) {
	bool ret = false;

	int x1 = x + dir[type][0][0];
	int y1 = y + dir[type][1][0];
	int x2 = x + dir[type][0][1];
	int y2 = y + dir[type][1][1];

	int reaction = action == 1 ? 0 : 1;

	if(safe(x1, y1, reaction) && safe(x2, y2, reaction)) {
		board[x][y] = board[x1][y1] = board[x2][y2] = action;
		ret = true;
	}
	return ret;
}
int cover() {
	int ret = 0;
	int x = -1, y = -1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) if(board[i][j] == 0) {
			x = i, y = j;
			break;
		}
		if(x != -1) break;
	}
	if(y == -1) return 1;
	for(int type = 0; type < 4; ++type) {
		if(f(x, y, type, 1)) {
			ret += cover();
			f(x, y, type, 0);
		}
	}
	return ret;
}

int main() {
	int tc; scanf("%d", &tc); while(tc--) {
		scanf("%d%d", &n, &m);
		char ch;
		int dotcnt = 0;
		for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
			scanf(" %c", &ch);
			if(ch == '#') board[i][j] = -1;
			else {
				++dotcnt;
				board[i][j] = 0;
			}
		}
		if(dotcnt % 3 != 0) puts("0");
		else printf("%d\n", cover());
	}
}