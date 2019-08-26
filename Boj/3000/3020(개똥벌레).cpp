#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 1;
int up[M], down[M];
int n, hei, num;
int main() {
	scanf("%d%d", &n, &hei);

	for(int i = 0; i < n; ++i) {
		scanf("%d", &num);
		if(i % 2) down[num]++;
		else up[num]++;
	}

	for(int i = hei - 2; i >= 1; --i) {
		down[i] += down[i + 1];
		up[i] += up[i + 1];
	}

    // 석순과 종유석의 크기는 H보다 작다.
    // 즉, 제일높은곳과 제일 낮은곳이 답이 될 수 있다.
	int ans = n / 2, cnt = 2;
	for(int i = 2; i < hei; ++i) {
		if(ans > up[hei - i + 1] + down[i]) {
			ans = up[hei - i + 1] + down[i];
			cnt = 1;
		} else if(ans == up[hei - i + 1] + down[i]) cnt++;
	}
	printf("%d %d\n", ans, cnt);
}

// 설명(Prefix Sum)
// 내가 해결한 방법은 배열의 구간합을 통해서 해결했다.
// 바닥에 있는 석순의 높이가 1,2,3,4,5 라고 해보자.
// 석순높이 1 2 3 4 5
// 충돌석순 5 4 3 2 1
// 이러한 형태를 뛰게 된다. 이렇게 석순과 종유석 배열의 구간합을 구한뒤
// 석순과 종유석이 충돌합이 최소가 되는 답을 찾으면 된다.