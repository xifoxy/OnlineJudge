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

// ����
// �־��� ������ ��� ���ڰ� ���� ������ �̷���� Ȯ���ϸ� �ȴ�.
// ���ϰ� �����ϱ� ���� string Ŭ������ �̿��ߴ�.
// ex) 123 �� �Ѽ��̴�. 101�� �Ѽ��� �ƴϴ�.
//	   135�� �Ѽ��̴�.
// �߰������� �������� �˼� �ִ°� �ϳ� �ִ�.
// 110�� �־������� �Ѽ��� ������ 99����� �Ѵ�.
// ���� Ȯ���غ��� �˰�����, 100~110���� �Ѽ��� ����. ��, 1~99 ������ �Ѽ���� �̾߱��.