#include <iostream>
#include <string>
using namespace std;
string s;
int main() {
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		s[i] -= 3;
		if(s[i] < 'A')
			s[i] = 'Z' - 'A' + s[i] + 1;
	}
	cout << s;
}

//����
//������ ���ڱ����̴�. A���� �������� �����ϸ�ȴ�.