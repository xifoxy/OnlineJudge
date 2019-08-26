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

//범위가 작은 쉬운 문제니 그냥 주어진 좌표에 값 다 집어넣고 더하면 된다.
//범위가 커지면 CCW?였나 이걸 공부해야 할것 같다.