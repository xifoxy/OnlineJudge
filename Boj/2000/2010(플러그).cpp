#include <bits/stdc++.h>
using namespace std;
int n, a, sum;
int main() {
	cin >> n >> a;
	sum += a;
	for(int i = 1; i < n; ++i) {
		cin >> a;
		sum += (a - 1);
	}
	cout << sum;
}

// �̷��� ��Ǯ�� �ڻ��ؾߵȴ�.