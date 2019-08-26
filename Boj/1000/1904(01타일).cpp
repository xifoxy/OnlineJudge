#include <iostream>
using namespace std;
int d[1000001], n;
int main() {
	d[1] = d[0] = 1;
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		d[i] = (d[i - 1] + d[i - 2]) % 15746;
	}
	cout << d[n] << '\n';
}

// 설명
// 답을 나열해보면 피보나치 수열이다.
// 이친수와 공식은 같다.