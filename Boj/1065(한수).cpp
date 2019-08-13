#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s;
bool sol(int x) {
	s = to_string(x);
	int cmp = s[1] - s[0];
	for(int i = 2; i < s.size(); ++i)
		if(s[i] - s[i - 1] != cmp)
			return false;
	return true;
}
int main() {
	cin >> n;
	if(n < 100) cout << n << '\n';
	else {
		for(int i = 100; i <= n; ++i)
			if(sol(i)) ans++;
		cout << ans + 99;
	}

}

// 설명
// 주어진 범위의 모든 숫자가 등차 수열을 이루는지 확인하면 된다.
// 편하게 구현하기 위해 string 클래스를 이용했다.
// ex) 123 은 한수이다. 101은 한수가 아니다.
//	   135는 한수이다.
// 추가적으로 예제에서 알수 있는게 하나 있다.
// 110이 주어졌을때 한수의 개수는 99개라고 한다.
// 직접 확인해보면 알겠지만, 100~110에는 한수가 없다. 즉, 1~99 까지는 한수라는 이야기다.