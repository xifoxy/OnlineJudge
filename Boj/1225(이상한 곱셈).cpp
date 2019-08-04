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

//이런거 못풀면 손목 잘라야 된다.
//크기를 유의하자.