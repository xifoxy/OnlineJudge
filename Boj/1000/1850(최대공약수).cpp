#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, g;
ll gcd(ll a, ll b) {
	if(a % b == 0) return b;
	return gcd(b, a % b);
}
int main() {
	cin >> a >> b;
	if(a < b) swap(a, b);
	for(int i = 1; i <= gcd(a, b); ++i)
		cout << 1;
}

//설명
//함정이 존재한다.
//그런대 나는 이해를 못했다. 이걸 볼때마다 설명이 있는 솔루션을 보자