#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, g;
ll gcd(ll a, ll b) {
	if(a % b == 0) return b;
	return gcd(b, a % b);
}
int main() {
	cin >> a >> b;
	if(a < b) swap(a, b);
	for(int i = 1; i <= gcd(a, b); ++i)
		cout << 1;
}

//����
//������ �����Ѵ�.
//�׷��� ���� ���ظ� ���ߴ�. �̰� �������� ������ �ִ� �ַ���� ����