#include <bits/stdc++.h>
using namespace std;
int n, d[10001], a;
int main() {
	cin >> n;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for(int i = 0; i < n; ++i) {
		cin >> a;
		d[a]++;
	}
	for(int i = 0; i <= 10000; ++i) {
		if(d[i]) for(int j = 0; j < d[i]; ++j)
			cout << i << '\n';
	}
}

//����
//������ �� ���� ������ N�� ������ 1 <= N <= 1e7 �̴�
//�̰� O(NlogN)���� �����ϸ� TLE�� �� �� �ۿ� ����.
//�� ������ �ٽ��� �ԷµǴ� ������ ������ 1������ �۰ų� ���� �ڿ����̱� ������
//�迭���ٰ� �ԷµǴ� ���� �ε����� ī���� ���ָ� �ȴ�.
//�����Ұ�, fastio�� ���� �����ָ� �̰Ͷ��� ������.