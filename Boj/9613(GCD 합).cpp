#include <bits/stdc++.h>
using namespace std;
int a, b, g, tc, d[101], n;
int gcd(int a, int b) {
	if(a % b == 0) return b;
	return gcd(b, a % b);
}
int main() {
	cin >> tc;
	for(int i = 0; i < tc; ++i) {
		cin >> n;
		for(int j = 0; j < n; ++j)
			cin >> d[j];

		long long ans = 0;
		for(int j = 0; j < n; ++j)
			for(int k = j + 1; k < n; ++k)
				ans += d[j] < d[k] ? gcd(d[k], d[j]) : gcd(d[j], d[k]);
		cout << ans << '\n';
	}
}

//����
//��Ž���� ���ϸ� �ȴ�. 
//��, ��ǲ���� 100���� ������ int���� �ѱ� �� �ִ�.