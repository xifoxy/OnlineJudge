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

// 설명
// N과 K가 작은 상황이고 1 <= K <= N <= 5e3 이기 때문에
// N^2으로 해결가능하다.