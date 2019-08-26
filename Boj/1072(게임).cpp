#include <bits/stdc++.h>
using namespace std;
const int M = 1e9;
int x, y, win_rate, l, r = M, ans = M + 1;
int avg(int total, int win) {
	return 1LL * win * 100 / total;
}
int main() {
	scanf("%d%d", &x, &y);
	win_rate = avg(x, y);
	while(l <= r) {
		int mid = (l + r) / 2;

        // 오른다면 더 작은 숫자를 찾는다.
		if(win_rate < avg(x + mid, y + mid)) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
        // 오르지 않는 다면 더 큰 숫자를 찾는다.
	}
	printf("%d\n", ans > M ? -1 : ans);
}

// 설명(Binary Search)
// 이분탐색으로 무난하게 풀리는 문제이다.
// 범위를 반토막씩 줄여가면 O(logN)이면 된다.