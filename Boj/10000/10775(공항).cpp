#include <bits/stdc++.h>
const int M = 1e5 + 1;
int d[M], G, P;
int find(int x) {
	if(x == d[x]) return x;
	return d[x] = find(d[x]);
}
int main() {
	scanf("%d%d", &G, &P);
	for(int i = 0; i <= G; ++i)
		d[i] = i;

	int ans = 0;
	for(int i = 0; i < P; ++i) {
		int plane;
		scanf("%d", &plane);
		plane = find(plane);
		if(plane == 0) break;
		d[plane]--;
		ans++;
	}
	printf("%d\n", ans);
}

// 설명(disjoint-set)
// 유니온파인드로 푸는 문제이다..
// 그런데 문제를 보고보고 또 봐도 이해가 잘 안간다
// 정답기반으로 추론만 가능할뿐-_-;

// example)
// 5 5
// 2 2 4 4 5
// answer = 5

// 4 4
// 1 4 4 4
// answer = 4

// 4 4
// 1 3 3 2
// answer = 3