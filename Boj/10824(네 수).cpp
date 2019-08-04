#include <bits/stdc++.h>
using namespace std;
long long ans;
int main() {
	string s1, s2, t;
	cin >> s1 >> s2;
	s1 = s1 + s2;
	cin >> t; s2 = t;
	cin >> t; s2 = s2 + t;
	ans = stoll(s1) + stoll(s2);
	cout << ans;
}

//설명
//숫자 크기에 유의하자.