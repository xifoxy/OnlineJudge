#include <bits/stdc++.h>
using namespace std;
int a, mx, idx;
int main() {
	for(int i = 0; i < 9; ++i) {
		cin >> a;
		if(a > mx) {
			mx = a;
			idx = i + 1;
		}
	}
	cout << mx << '\n' << idx;
}

// �̷��� ��Ǯ�� �ڻ��ؾ�..