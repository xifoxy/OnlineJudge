#include <bits/stdc++.h>
using namespace std;
int d[26], odd_cnt, odd_idx = 99;
string pa, ans;
int main() {
	cin >> pa;
	for(int i = 0; i < pa.size(); ++i)
		d[pa[i] - 'A']++;

	for(int i = 0; i < 26; ++i) if(d[i] % 2) {
		odd_idx = i;
		odd_cnt++;
	}

	if((pa.size() % 2 == 0 && odd_cnt) || odd_cnt > 1) cout << "I'm Sorry Hansoo";
	else {
		for(int i = 0; i < 26; ++i) {
			for(int j = 0; j < d[i] / 2; ++j) {
				ans.push_back(i + 'A');
			}
		}
		cout << ans;
		if(odd_idx != 99) cout << char('A' + odd_idx);
		reverse(ans.begin(), ans.end());
		cout << ans;
	}
}

// ����(Palindrome? ����)
// �־��� ���ڿ��� �Ӹ������ ������� ��� ������ �ʿ��ϴ�.
// 1. ���ڿ��� ���̰� ¦���϶�
//  -���ڿ��� ���̰� ¦���ε� ¦�� ���� �ʴ� �� ���� ���ĺ��� ���� �Ѵٸ� �Ӹ������ ���� �� ����.
//   ex) AA(B)(C) ���⼭ B�� C�� ���� ���ĺ��̴�

// 2. ���ڿ��� ���̰� Ȧ���϶�
//  -���ڿ��� ���̰� Ȧ���ε� ���� ���ĺ��� �ΰ� �̻� ���� �Ѵٸ� �Ӹ������ ���� �� ����.

// �ΰ��� ���ǿ� �ش����� �ʴ� �ٸ� �и������ ����� �ȴ�.
// �Էµ� ���ڿ��� ���ĺ��� ī��Ʈ�ؼ� A~Z������� ���ÿ� �׾� �Ӹ������ ���ݺθ� �����
// ����� �Ĺݺθ� ����Ѵ�.