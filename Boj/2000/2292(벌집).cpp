#include <bits/stdc++.h>
using namespace std;
long long sum = 1;
int n, i;
int main() {
	sum = 1;
	cin >> n;
	for(i = 1; sum < n; ++i) {
		sum = sum + (i * 6);
	}
	cout << i << '\n';
}

//������ ������ ������ ������ �� ���캸�� 6�� ����� �����Ѵ�.
//6�� ������ ���ȴ�.