#include <iostream>
#include <string>
using namespace std;
string in, ans, temp;
void sol(int n) {
	if(n == 0) return;
	char t = n % 2 + '0';
	temp = t + temp;
	sol(n / 2);
}
int main() {
	cin >> in;
	if(in[0] == '0') ans = '0';
	else for(int i = 0; i < in.size(); ++i) {
		temp = "";
		sol(in[i] - '0');
		if(i != 0 && temp.size() < 3) {
			for(int i = temp.size(); i < 3; ++i)
				temp = '0' + temp;
		}
		ans += temp;
	}
	cout << ans << '\n';
}

// ����(����)
// 8�������� �ִ� ���ü� �ִ� ���� 7�̴�. �̰� 2����ȭ �غ��� 111�̴�.
// �� 8������ �� �ڸ��� ���� �ִ�� ���ü� �ִ� ���̴� 3�̶�� ���̴�.
// ù°�ڸ� ���ڸ� �����ϰ� ���δ� 3�ڸ��� ������ָ� �ȴ�.