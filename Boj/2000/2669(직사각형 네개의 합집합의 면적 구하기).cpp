#include <bits/stdc++.h>
using namespace std;
int d[101][101], cnt;
int main() {
	for(int sq = 0; sq < 4; ++sq) {
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;
		if(x > x1) swap(x, x1);
		if(y > y1) swap(y, y1);
		for(int i = x; i < x1; ++i) {
			for(int j = y; j < y1; ++j) {
				if(!d[i][j]) {
					cnt++;
					d[i][j] = 1;
				}
			}
		}
	}
	printf("%d\n", cnt);
}

// 설명
// 범위가 작으니 그냥 주어진 좌표에 값 집어넣고 더하면된다.