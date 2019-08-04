#include <bits/stdc++.h>
using namespace std;
int n, d[10001], a;
int main() {
	cin >> n;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for(int i = 0; i < n; ++i) {
		cin >> a;
		d[a]++;
	}
	for(int i = 0; i <= 10000; ++i) {
		if(d[i]) for(int j = 0; j < d[i]; ++j)
			cout << i << '\n';
	}
}

//설명
//문제를 잘 보면 범위가 N의 범위가 1 <= N <= 1e7 이다
//이걸 O(NlogN)으로 정렬하면 TLE가 될 수 밖에 없다.
//이 문제의 핵심은 입력되는 숫자의 범위가 1만보다 작거나 같은 자연수이기 때문에
//배열에다가 입력되는 값을 인덱스로 카운팅 해주면 된다.
//주의할건, fastio를 적용 안해주면 이것또한 터진다.