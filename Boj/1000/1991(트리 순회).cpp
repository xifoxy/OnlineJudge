#include <bits/stdc++.h>
using namespace std;
char d[27][3], p;
int n;
void pre(int cur) {
	if(!(cur >= 0 && cur <= 26)) return;
	printf("%c", cur + 'A');
	pre(d[cur][0] - 'A');
	pre(d[cur][1] - 'A');
}
void in(int cur) {
	if(!(cur >= 0 && cur <= 26)) return;
	in(d[cur][0] - 'A');
	printf("%c", cur + 'A');
	in(d[cur][1] - 'A');
}
void pos(int cur) {
	if(!(cur >= 0 && cur <= 26)) return;
	pos(d[cur][0] - 'A');
	pos(d[cur][1] - 'A');
	printf("%c", cur + 'A');
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf(" %c", &p);
		for(int j = 0; j < 2; ++j) {
			scanf(" %c", &d[p - 'A'][j]);
		}
	}
	pre(0); puts("");
	in(0); puts("");
	pos(0); puts("");
}

// 설명
// 문제를 잘 읽어보면, 친절하게 재귀 순서까지 설명해준다.
// 인풋받을때 parent노드 받는 방법과,
// 함수의 기저 사례 그리고 출력 및 재귀 값 넘겨주는것만 아이디어 구현하면 된다.