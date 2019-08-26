#include <bits/stdc++.h>
using namespace std;
int a[500001], n, m, num, l, r, mid, ans;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < 500001; ++i) a[i] = 999999999;
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	sort(a, a + n);
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d", &num);
		l = 0; r = n;
		while(l <= r) {
			mid = (l + r) / 2;
			if(a[mid] < num) l = mid + 1;
			else r = mid - 1;
		}
		ans = l;
		l = 0; r = n;
		while(l <= r) {
			mid = (l + r) / 2;
			if(a[mid] <= num) l = mid + 1;
			else r = mid - 1;
		}
		ans = r - ans + 1;
		printf("%d ", ans);
	}
}

//설명
//이분탐색을 응용한 로우바운드와 어퍼바운드가 필요하다.
//로우바운드 : 정렬된 숫자에서 원하는 숫자의 첫번째 위치
//어퍼바운드 : 정렬된 숫자에서 원하는 숫자의 마지막 위치
//인덱스를 제한하는 세밀한 구현이 떠오르지 않아서 배열 전체를 충분히 큰수로 초기화 했다.
//이분탐색을 변형한 로우바운드, 어퍼바운드 구현만 눈여겨 보면 될것 같다.