#include <bits/stdc++.h>
using namespace std;
int d[5000001];
int n, k;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> d[i];

	sort(d, d + n);
	cout << d[k - 1] << '\n';
}

//����
//������ fastio�̰� �����ϸ� �ӵ��� ��������
//�ǹ� ���ٰ� �����Ѵ�.
//������ N���� ���ڸ� �Է¹޾� ����������
//K��° ��ġ�� �ִ� ���� ���ϴ°��̴�.
//1 <= N <= 5e6 �̱⶧����
//���Ŀ� NlogN�� �ϸ� �뷫 5õ���� ���´�.
//�׳� �Է¹ް� �����ϰ� �������.