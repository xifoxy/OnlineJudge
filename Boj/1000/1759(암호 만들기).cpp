#include <bits/stdc++.h>
using namespace std;
const int MX = 16;
char pass[MX];
int n, m;
void backt(int pos, string &print, int aeiou, int other) {
	if(print.size() == n) {
		if(aeiou >= 1 && other >= 2)
			cout << print << '\n';
		return;
	}

	for(int i = pos; i < m; ++i) {
		char t = pass[i];
		print.push_back(t);
		if(t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u')
			backt(i + 1, print, aeiou + 1, other);
		else backt(i + 1, print, aeiou, other + 1);
		print.pop_back();
	}
}
int main() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
		cin >> pass[i];

	sort(pass, pass + m);
	string print = "";
	backt(0, print, 0, 0);
}

//����
//������ �� �о�� N���ڷ� �̷���� ��ȣ�ӿ� ���� >= 1 && ���� >= 2
//��� ������ �ִ�. �̰͸� �� ��Ű�� ���� ������ ����.