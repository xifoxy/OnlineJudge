#include <bits/stdc++.h>
using namespace std;
string in;
int main() {
	getline(cin, in);
	int idx = 0, ans = 0;
	while(idx < in.size()) {
		if(isalpha(in[idx]))
			ans++;
		while(idx < in.size() && in[idx++] != ' ');
	}
	cout << ans;
}

// ����
// ���ڿ��� ��¥�� ���� �ʿ䰡 �ִ�.
// string Ŭ������ ������ �������� ���� �ޱ� ������ getline�Լ��� ��� �Ѵ�.