#include <bits/stdc++.h>
using namespace std;
const int MX = 2200;
string s;
int n, ans;
int d[37];
int main() {
	cin >> s >> n;
	d[1] = n;
	for(int i = 2; i < s.size(); ++i) {
		d[i] = d[i - 1] * n;
	}
	reverse(s.begin(), s.end());
	for(int i = 0; i < s.size(); ++i) {
		int t = 0;
		if(s[i] >= '0' && s[i] <= '9')
			t += s[i] - '0';
		else t += s[i] - 'A' + 10;
		if(!i) ans += t;
		else ans += (t * d[i]);
	}
	cout << ans;
}

// ����
// �������̴�. N�����̸� �ڸ������� ���� �����ָ� �ȴ�.
// �ڸ����� ���� ���ڰ��� ���ڷ� ġȯ�ؼ� �����ָ� �� �ڸ��� ���� �ȴ�.