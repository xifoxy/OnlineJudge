#include <bits/stdc++.h>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	if(a.size() < b.size()) swap(a, b);

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int len = a.size();
	for(int i = 0; i < len; ++i) {
		int num = a[i] - ('0' * 2);
		if(i >= b.size()) num += '0';
		else num += b[i];
		a[i] = (num % 10) + '0';

		num /= 10;
		if(num) {
			if(i + 1 == a.size())
				a.push_back('1');
			else a[i + 1]++;
		}
	}

	reverse(a.begin(), a.end());
	cout << a << '\n';
}

// 설명
// 적당히 문자열로 처리하면 된다.