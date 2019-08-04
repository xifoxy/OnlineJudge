#include <bits/stdc++.h>
using namespace std;
char pic[64][64];
int N;
bool isAll0(int x, int y, int sz) {
	for(int i = x; i < x + sz; i++) {
		for(int j = y; j < y + sz; j++) {
			if(pic[i][j] == '1')
				return false;
		}
	}
	return true;
}
bool isAll1(int x, int y, int sz) {
	for(int i = x; i < x + sz; i++) {
		for(int j = y; j < y + sz; j++) {
			if(pic[i][j] == '0')
				return false;
		}
	}
	return true;
}

string quadtree(int x, int y, int sz) {
	if(isAll0(x, y, sz))
		return "0";
	if(isAll1(x, y, sz))
		return "1";
	int m = sz / 2;
	return "(" + quadtree(x, y, m) + quadtree(x, y + m, m) + quadtree(x + m, y, m) + quadtree(x + m, y + m, m) + ")";
}
int main(void) {
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%s", pic[i]);
	cout << quadtree(0, 0, N);
}

//설명
//우선 종이의 개수와 쿼드트리는 보고 따라적은것에 불과하다.
//종이의 개수를 쉽게 이해하고나니 쿼드트리도 이해는 간다.
//우선 좋은 소스를 공개해주신 바킹독님께 감사의 인사를 드린다.
//
//종이의 개수 문제가 숫자3이라는게 핵심이었다면
//쿼드트리는 2가 핵심이다. 잘 가지고 놀아봐야겠다.