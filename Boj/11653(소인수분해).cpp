#include <bits/stdc++.h>
using namespace std;
int a, s = 2;
int main() {
	cin >> a;
	while(a > 1) {
		if(a % s) s++;
		else {
			cout << s << '\n';
			a /= s;
		}
	}
}

//�̷��� ��Ǯ�� �ڻ��ؾߵȴ�.