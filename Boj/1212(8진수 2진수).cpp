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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
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

//����
//���� ������ �� �ڸ��� ���� ��Ʈ�� ī��Ʈ �ϴ¹����� �ذ��ߴ�.
//�Ѱ��� �����ؾ� �� ������ �� �ڸ������� ��Ʈ�� ī��Ʈ�ؼ� ���ϵ�,
//8������ ��� 2��ȭ�� �ڸ������� �ִ� 3�ڸ����� ���;� �Ѵ�.
//ù �ڸ��� �����ϰ� 3�ڸ��� �ȵǸ� �׸�ŭ 0�� �����༭ �ذ��Ѵ�.
//������ʷ� 0�϶��� ������ 0�� ����Ѵ� ��� ������ ���� ������ ����ó���� �Ǵ� ��������.