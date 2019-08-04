#include <bits/stdc++.h>
using namespace std;
long long d[101]{1,1,1};
int tc, n;
int main() {
	for(int i = 3; i <= 100; ++i)
		d[i] = d[i - 2] + d[i - 3];
	cin >> tc;
	while(tc--) {
		cin >> n;
		cout << d[n - 1] << '\n';
	}
}

//설명
//바보같이 데이터 타입을 맞추지 않아 또 틀렸다--
//규칙을 찾아보도록 하자
//찾으면 좋지만 못찾아도 상관없다.
//아래 사이트를 참조하도록 하자.
//https://oeis.org/A000931
