#include <bits/stdc++.h>
char field[101][101];
int main() {
	int n, row_cnt = 0, col_cnt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%s", &field[i]);
	}

	for(int i = 0; i < n; ++i) {
		int row = 0, col = 0;
		for(int j = 0; j < n; ++j) {
			field[i][j] == '.' ? col++ : col = 0;
			field[j][i] == '.' ? row++ : row = 0;
			if(row == 2) row_cnt++;
			if(col == 2) col_cnt++;
		}
	}
	printf("%d %d\n", col_cnt, row_cnt);
}

// ����(Brute Force)
// �� ��� ���� ���� Ž���ؼ� ���� �ڸ��� �����Ѵٸ� ��������.