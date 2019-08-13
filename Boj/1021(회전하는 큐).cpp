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

// 설명(Simulation)
// 뽑아야 하는 숫자의 순서가 정해져 있기 때문에 현재 노드 위치와 
// 뽑아야 할 노드 위치를(좌우 방향중 짧은곳) 찾아 뽑으면 된다.
