#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int ret(int a, int b) {
	// 자연수의 0 제곱은 1이다.
	if(b == 0) return 1;
	int t = ret(a, b / 2);
	int r = 1LL * t * t % c;
	// 홀수일 경우
	// ex) 짝수를 쪼개서 홀수가 나올 경우 10^10 10^18
	if(b % 2) r = 1LL * r * a % c;
	return r;
}
int main() {
	cin >> a >> b >> c;
	cout << ret(a, b) << '\n';
}

// 설명(Divide ans Conquer)
// A를 B번 곱한 수를 알고싶다. 이 말은 A를 B번 제곱한다는 뜻이다.
// Brute Force로 풀기에는 A,B,C의 크기가 21억이어서 너무 크다.
// 이걸 2초에 해결 하기 위해선 곱셈공식을 이용해서 분할 해야할 필요가 있다.
// ex) 10^10000 = 10^5000 * 10^5000 이다