#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
	cin >> a;
	for(int i = 0; i < 9; ++i) {
		cin >> b;
		a -= b;
	}
	cout << a;
}

//�̷��� ��Ǯ�� �ڻ��ؾߵȴ�.