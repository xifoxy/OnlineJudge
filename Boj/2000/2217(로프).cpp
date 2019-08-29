#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 1;
int loaf[MAX], n;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &loaf[i]);
	}
	sort(loaf, loaf + n, greater<int>());
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		sum = max((i + 1) * loaf[i], sum);
	}
	printf("%d\n", sum);
}

// 설명(Math)
// 문제의 설명은 주어진 로프를 병렬로 연결했을때 잴 수 있는 최대 무게이다. 단, 무게는 균등하게 분배된다.

// 15, 9, 10 3개의 로프가 있다고 가정해보자.
// 로프를 하나를 달았을때는 측정 가능한 최대 무게는 15이다.
// 그럼 2개는? 로프가 큰 순서대로 봤을때 15, 10이기에 로프 하나당 부과되는 무게는 최대 10이다.
// 그러니까 로프 2개는 10 + 10 총 20의 무게가 측정가능하다.
// 3개의 경우는 15, 10, 9 최소 무게가 9이기 때문에 9 + 9 + 9로 27이 된다.

// 로프를 N개 달았을 경우엔 N * (부과 가능한 무게가 가장 작은 로프) 가 되기 때문에
// 내림차순으로 정렬후 순차탐색해주면 되겠다.