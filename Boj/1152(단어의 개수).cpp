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

//����
//�켱 ���� ���ڸ� �Է¹������� ���� �ٸ� ����� �ʿ��ϴ�.
//���� string�� �����߱⶧���� getline�� �̿��ߴ�.
//�׸��� ���鹮�ڰ� ���� ó�� Ȥ�� ���� ������ �׸��� �ΰ��̻� �� ��츦 �����ؾ��Ѵ�.
//do while���� ������ �ƴϸ� ��ó�� ���°��� ������ ����ֵ簡.