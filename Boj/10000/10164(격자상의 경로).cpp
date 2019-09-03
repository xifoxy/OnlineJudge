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
    // 숫자의 위치 좌표
	int x = p / m;
	int y = p % m;
	y--;
	if(p % m == 0) {
		y = m - 1;
		x--;
	}

    // 거쳐야 하는 숫자가 없는 경우 좌표가 깨지게 된다
    // 그걸 예방하기 위해 예외처리한다.
    if(!p) x = 0, y = 0;
    printf("%d\n", sol(0, 0, x, y) * sol(x, y, n-1, m-1));
}

// 설명(DP)
// [0,0] -> [x,y] -> [n-1,m-1]로 가는 경우의 수를 구하는 문제이다. 이걸 풀어서 말하면
// 좌표[0,0] -> 임의의 숫자[x,y] 로 가는 경우의 수와
// 임의의 숫자[x,y] -> 좌표[n-1,m-1] 로 가는 경우의 수를 곱하면 문제에서 원하는 조건이 된다.