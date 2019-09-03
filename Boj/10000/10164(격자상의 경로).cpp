#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int dp[16][16];
bool safe(int x, int y, int xx, int yy){
	return x >= 0 && y >= 0 && x <= xx && y <= yy;
}

int dx[]{1,0}, dy[]{0,1};
int sol(int x, int y, int xx, int yy){
	int &ret = dp[x][y];
	if(x == xx && y == yy) return 1;
	if(ret) return ret;
	for(int direction = 0; direction < 2; ++direction){
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		if(safe(nx, ny, xx, yy)) ret += sol(nx, ny, xx, yy);
	}
	return ret;
}
int main(){
	scanf("%d%d%d", &n, &m, &p);
    // ������ ��ġ ��ǥ
	int x = p / m;
	int y = p % m;
	y--;
	if(p % m == 0) {
		y = m - 1;
		x--;
	}

    // ���ľ� �ϴ� ���ڰ� ���� ��� ��ǥ�� ������ �ȴ�
    // �װ� �����ϱ� ���� ����ó���Ѵ�.
    if(!p) x = 0, y = 0;
    printf("%d\n", sol(0, 0, x, y) * sol(x, y, n-1, m-1));
}

// ����(DP)
// [0,0] -> [x,y] -> [n-1,m-1]�� ���� ����� ���� ���ϴ� �����̴�. �̰� Ǯ� ���ϸ�
// ��ǥ[0,0] -> ������ ����[x,y] �� ���� ����� ����
// ������ ����[x,y] -> ��ǥ[n-1,m-1] �� ���� ����� ���� ���ϸ� �������� ���ϴ� ������ �ȴ�.