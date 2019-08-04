#include <bits/stdc++.h>
using namespace std;
char board[10][10], word[11];
bool visit[10][10][10];
int dx[]{-1,-1,-1,0,0,1,1,1};
int dy[]{-1,0,1,-1,1,-1,0,1};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < 5 && y < 5;
}

bool sol(int pos, int sz, int x, int y) {
	visit[pos][x][y] = true;
	if(pos == sz - 1) {
		return true;
	}
	bool ans = false;
	for(int i = 0; i < 8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!ans && safe(nx, ny) && !visit[pos + 1][nx][ny] && board[nx][ny] == word[pos + 1]) {
			ans = sol(pos + 1, sz, nx, ny);
		}

	}
	return ans;
}

int main() {
	int tc, word_cnt;
	scanf("%d", &tc);
	while(tc--) {
		for(int i = 0; i < 5; ++i)
			scanf("%s", &board[i]);

		scanf("%d", &word_cnt);
		for(int i = 0; i < word_cnt; ++i) {
			memset(word, 0, sizeof(word));
			memset(visit, false, sizeof(visit));
			scanf("%s", word);
			int sz = strlen(word);
			bool ans = false;
			for(int x = 0; x < 5; ++x) {
				if(!ans) for(int y = 0; y < 5; ++y) {
					if(!ans && board[x][y] == word[0])
						ans = sol(0, sz, x, y);
				}
			}
			printf("%s %s\n", word, ans ? "YES" : "NO");
		}
	}
}