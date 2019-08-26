#include <bits/stdc++.h>
using namespace std;
int a, b;
int gcd(int a, int b) {
	if(a % b == 0) return b;
	return gcd(b, a % b);
}
int main() {
	cin >> a >> b;
	if(b > a) swap(a, b);
	int g = gcd(a, b);
	cout << g << '\n' << a*b / g;
}

//설명
//유클리드 호제법을 참조하자
//최소 공배수는 (a * b / 최대공약수)로 구해진다.