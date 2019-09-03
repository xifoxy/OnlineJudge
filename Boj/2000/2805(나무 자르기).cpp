#include <bits/stdc++.h>
using namespace std;
int a[1000001], n, m;
long long l, r = 10000000000, mid, sum;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	while(l + 1 < r) {
		mid = (l + r) / 2;
		sum = 0;
		for(int i = 0; i < n; ++i) {
			if(a[i] > mid) {
				sum += a[i] - mid;
				if(sum >= m) break;
			}
			
		}
		if(sum >= m) l = mid;
		else r = mid;
	}
	cout << l;
}

// 설명
// 아이디어는 랜선자르기와 같다.
// 0.5초나 나와서 좀 빠른 소스를 봤는데 조금더 빠른 최적화 기법이 있기에 따라했다.
// 핵심은 구해야 하는 나무보다 더 많이 잘리는 경우는 내부 포문을 멈추는것이다.
// 이건 인풋데이터가 100만개가 되기 때문에 생각해보면 제법 효율적인 방법이 된다.
// 자르는 높이보다 낮은경우 자르지 않는 부분을 잘 살펴보자.