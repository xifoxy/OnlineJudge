#include <bits/stdc++.h>
using namespace std;

int main() {
	deque<int> dq;
	int n, m, a, ans = 0;
	scanf("%d %d", &n, &m);
	dq.resize(n);
	for(int i = 1; i <= n; ++i)
		dq[i - 1] = i;
	for(int i = 0; i < m; ++i) {
		scanf("%d", &a);
		int idx = 0;
		for(idx = 0; idx < dq.size(); ++idx) {
			if(dq[idx] == a) break;
		}
		if(dq[0] != a) {
			if(idx < dq.size() - idx) for(int k = 0; k < idx; ++k) {
				ans++;
				dq.push_back(dq.front()), dq.pop_front();
			} else for(int k = 0; k < dq.size() - idx; ++k) {
				dq.push_front(dq.back()), dq.pop_back();
				ans++;
			}
		}
		dq.pop_front();
	}
	printf("%d\n", ans);
}

//����
//�־��� ���ڸ� ������� �����ؾ� �ϴϱ�
//�׸����ϰ� Ǯ��ȴ�.