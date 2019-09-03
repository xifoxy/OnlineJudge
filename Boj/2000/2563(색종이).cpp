#include <bits/stdc++.h>
using namespace std;
int paper[101][101], n, y, x, ans;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &y, &x);
		for(int xx = x; xx < x + 10; ++xx)
			for(int yy = y; yy < y + 10; ++yy)
				paper[xx][yy] = 1;

	}

	for(int xx = 1; xx <= 100; ++xx)
		for(int yy = 1; yy <= 100; ++yy)
			if(paper[xx][yy]) ans++;

	printf("%d\n", ans);
}

// 설명(Brute Force)
// 범위가 작으니까 완전탐색으로 색칠공부 하면된다.