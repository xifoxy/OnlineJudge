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

//문제에 답이 나와있으니 생략.