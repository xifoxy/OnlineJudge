#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	int a, b, c, d, g;
	cin >> a >> b >> c >> d;
	int p = b * d, s = a * d + b * c;
	g = gcd(s, p);
	printf("%d %d\n", s / g, p / g);
}

// 설명(GCD)
// 두 분수의 합을 기약분수(더이상 나눠지지 않는 분수)로 만드는 문제이다.
// 분모와 분자의 최대공약수를 구해서 출력하자.