#include <bits/stdc++.h>
using namespace std;
string a, b;
int main() {
	long long ans = 0;
	cin >> a >> b;
	for(int i = 0; i < a.size(); ++i) {
		int anum = a[i] - '0';
		for(int j = 0; j < b.size(); ++j) {
			int bnum = b[j] - '0';
			ans += (anum * bnum);
		}
	}
	cout << ans;
}

// 설명(Brute Force)
// 문제 자체는 쉽다. 단, 숫자의 길이가 1e4자리가 된다는것만 주의하면 된다.