#include <bits/stdc++.h>
using namespace std;
const int MX = 2200;
int a[MX][MX], n;
int ans[3];
bool check(int x, int y, int s) {
	int cmp = a[x][y];
	for(int i = x; i < x + s; ++i)
		for(int j = y; j < y + s; ++j)
			if(cmp != a[i][j])
				return false;
	return true;
}

void sol(int x, int y, int s) {
	if(check(x, y, s)) {
		ans[a[x][y] + 1]++;
		return;
	}
	int m = s / 3;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			sol(x + i * m, y + j * m, m);
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	sol(0, 0, n);
	printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
}

// ����
// ���������� ������ ������ �ȵǴ� �����̴�.
// ������ ũ��� 3^N���� �־����� ������ �� ���캸��
// 3*3�ȿ� ���ڰ� �ϳ��� ���ϵ��� ������ ���δ� �������� �����Ѵ�.
// N�� ũ�Ⱑ 3�� ������ �̱� ������ 3�̶�� ���ڸ� �� ������ ��� ���� ������ �ȴ�.