#include <bits/stdc++.h>
using namespace std;
int a[200001], n, m, s;
long long l, r = 10000000000, mid, ans, cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);
	while(l + 1 < r) {
		mid = (l + r) / 2;
		cnt = 1;
		s = a[0];
		for(int i = 1; i < n; ++i) {
			if(a[i] - s >= mid) {
				cnt++;
				s = a[i];
				if(cnt >= m) break;
			}
		}
		if(cnt >= m) {
			ans = mid;
			l = mid;
		} else r = mid;
	}
	cout << ans;
}

// 설명
// 이건 몇번봐도 문제 이해가 잘 되지 않았는데 이제는 좀 되는것 같다.
// 이 문제의 포인트는 공유기를 최대한 멀리 설치하는것이다.
// 우선 순차탐색을 위해선 주어진 좌표를 정렬할 필요가 있다.
// 기본 예제를 가지고 답을 구해보자면
// N = 5 C = 3
// x = 1, 2, 4, 8, 9
// 공유기를 3개 설치하는데 거리를 최대로 만들려면?
// 우선 탐색 조건을 2로 잡으면
// 2이상 되는 거리에 좌표공유기를 설치 할 수 있다
// 1, 4, 8 이렇게 설치하면 공유기 사이의 거리가 2보다 크거나 같은 답이 되는것이다.
// 그럼 4로 잡아보면 공유기를 2개 밖에 설치 못한다.
// 1, 8
// 그럼 거리가 3보다 크거나 같은 공유기 설치는?
// 1, 4, 8 거리 2와 같아 지니 거리의 최댓값은 3이다.