#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	deque<int> dq(n);
	for(int i = 1; i <= n; ++i) {
		dq[i - 1] = i;
	}

	while(dq.size() != 1) {
		dq.pop_front();
		dq.push_back(dq.front());
		dq.pop_front();
	}
	printf("%d\n", dq.front());
}

// 설명(List)
// 그냥 잘 넣고 빼자.