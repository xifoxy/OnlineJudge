#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for(int i = 0; i < n; ++i)
		q.push(i + 1);

	cout << '<';
	while(!q.empty()) {
		for(int i = 0; i < k; ++i) {
			if(i == k - 1) {
				cout << q.front();
				q.pop();
			} else {
				q.push(q.front());
				q.pop();
			}

		}
		if(!q.empty()) cout << ", ";
		else cout << '>';
	}
}

// ����
// N�� K�� ���� ��Ȳ�̰� 1 <= K <= N <= 5e3 �̱� ������
// N^2���� �ذᰡ���ϴ�.