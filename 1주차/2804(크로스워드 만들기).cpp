#include <bits/stdc++.h>
using namespace std;
const int M = 31;
char board[M][M];
char str1[M], str2[M];
int n, m;
int main() {
	scanf("%s %s", str1, str2);
	for(n = 0; str1[n]; ++n);
	for(m = 0; str2[m]; ++m);
	fill(&board[0][0], &board[M - 1][M], '.');
	bool cmp = true;
	int x = 0, y = 0;
	for(int i = 0; i < n && cmp; ++i) {
		for(int j = 0; j < m && cmp; ++j) {
			if(str1[i] == str2[j]) {
				cmp = false;
				x = i, y = j;
			}
		}
	}
	for(int i = 0; i < n; ++i) board[y][i] = str1[i];
	for(int i = 0; i < m; ++i) board[i][x] = str2[i];
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j)
			printf("%c", board[i][j]);
		puts("");
	}
}

// 설명
// 말하지 않아도 알아요~