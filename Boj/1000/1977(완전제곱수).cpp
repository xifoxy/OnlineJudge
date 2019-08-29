#include <bits/stdc++.h>
using namespace std;
int a, b, l, sum, mn = 1e6;
int main() {
	cin >> a >> b;
	l = sqrt(a);
	if(l * l < a) ++l;
	for(int i = l; i * i <= b; ++i) {
		mn = min(mn, i * i);
		sum += (i * i);
	}
	if(!sum) cout << -1;
	else cout << sum << '\n' << mn;
}

// 설명(Math)
// 정말 쉽다. 주어진 범위 안에서 제곱근이 정수가 되는 수를 구하면 된다.