#include <bits/stdc++.h>
using namespace std;
const int M = 1e6;
int d[M * 2 + 1];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		d[a + M]++;
	}

	for(int i = 0; i <= M * 2; ++i) {
		for(int j = 0; j < d[i]; ++j) {
			printf("%d\n", i - M);
		}
	}
}

// 설명
// 제한시간이 10초인데 테스트케이스가 몇개인지 알수 없다.
// Qsort의 최악의 시간복잡도는 O(N^2)이기 때문에 1e6개의
// 데이터를 처리하기엔 다소 문제가 있다.

// 하지만 다행인점은 데이터가 1e6개 라는 점과 데이터의 크기가
// -1e6 <= A <= 1e6 라고 명시 되어 있기 때문에 O(N)혹은 O(NlogN)의 시간복잡도를
// 가지는 제한적 범위에서 전자로 경우로 동작하는 unstable_sort인 Radix를 이용하거나
// stable_sort인 merge_sort를 이용하면 된다.

// 또 다른 꼼수로 데이터의 범위를 이용해서 해당 숫자를 카운팅 하는방법이 있다.
// 나는 이방법으로 풀었다.

// ..# 데이터의 부재 때문인지 stable_sort와 크게 속도차이가 나지 않는다.