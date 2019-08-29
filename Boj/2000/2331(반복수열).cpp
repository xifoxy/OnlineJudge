#include <bits/stdc++.h>
using namespace std;
int n, m, idx = 1;
map<int, int> mp;
int dfs(int num, int p) {
	int sum = 0;
	while(num != 0) {
		sum += pow(num % 10, p);
		num /= 10;
	}
	if(mp[sum]) return mp[sum];
	mp[sum] = ++idx;
	return dfs(sum, p);
}
int main() {
	cin >> n >> m;
	mp[n] = 1;
	cout << dfs(n, m) - 1;
}

// ����(DP)
// �������� �䱸�ϴ� ��Ģ��� ���ڸ� ����� ���µ�,
// �ݺ������� ��Ÿ���� �ݺ������� �ƴ� ���ڵ��� ������ ����϶�� �Ѵ�.
// 57, 2 ��� �ԷµǸ�
// 57, 74, 65, 61, [37), 58, 89, 145, 42, 20, 4, (16], 37, 58...
// 37���� �ݺ� ���� �����̰� 16�� �ݺ� ���� �����̴�,
// ������ ������ ���ڴ� 4���̹Ƿ� ���� 4�� �ȴ�.