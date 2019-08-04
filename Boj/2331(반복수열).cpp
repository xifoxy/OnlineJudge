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

//����
//��� ���� �ڷᱸ���� �̿��Ϸ��� ������ ����� �������� �ʾƼ� map�� �̿��ߴ�.
//������ ��Ģ�� �����ϴ�. �ݺ������� �߰ߵǸ� 
//�ݺ������� �ƴ� ������ ������ ī�����ؼ� ����ϸ� �ȴ�.