#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 1;
int shortest[M], path[M];
bool cmp(int x, int cur) {
	return shortest[x] >= shortest[cur] + 1;
}
bool zero(int cur) {
	return !shortest[cur];
}
bool safe(int x, int cur) {
	return x >= 0 && x < M && (zero(x) || cmp(x, cur));
}
void f(int x, int cur) {
	shortest[x] = zero(x) ? shortest[cur] + 1 : min(shortest[x], shortest[cur] + 1);
}
int main() {
    int st, ed;
	scanf("%d%d", &st, &ed);
	queue<int> Q;
	Q.push(st);
	shortest[st] = 1;
	while(!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		if(cur == ed)
			path[shortest[cur] - 1]++;
		if(safe(cur * 2, cur)) {
			Q.push(cur * 2);
			f(cur * 2, cur);
		}
		if(safe(cur - 1, cur)) {
			Q.push(cur - 1);
			f(cur - 1, cur);
		}
		if(safe(cur + 1, cur)) {
			Q.push(cur + 1);
			f(cur + 1, cur);
		}
	}
	int ans = shortest[ed] - 1;
	printf("%d\n%d\n", ans, path[ans]);
}

// 설명(BFS)
// 1. 그리디한 솔루션이다. 중복 방문과 이동 카운트를 
// 최소화 하기 위해 메모이제이션을 이용한다.
// 2. 소스를 작성하다보니 너무 너덜너덜해 보여서 함수화로 만들었다.
// 3. safe함수에서 호출하는 zero와 cmp는 방문하지 않았을 경우와 대소관계이다.
// 4. 숨바꼭질 1,3,4와는 다르게 경로의 수를 답으로 출력해야 하기 때문에 도착지점에서의
// 이동시간을 따로 메모를 한다(27번줄)