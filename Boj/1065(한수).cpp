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

//������ ������ ������������ Ȯ���ϴ� �����̴�.
//N�� ������ 1000 >= N�̴� ���̺��ϰ� ���ڿ��� �̿��ؼ� Ǯ��ȴ�.