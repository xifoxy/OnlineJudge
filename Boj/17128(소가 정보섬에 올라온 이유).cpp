#include <bits/stdc++.h>
using namespace std;
const int R = 2e5 + 1;
int d[R], n, q, a;
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; ++i)
		scanf("%d", d + i);
	vector<int> ans(n, 1);
	for(int i = 0; i < n; ++i) {
		for(int j = 3; j >= 0; --j) {
			if(i - j < 0)
				ans[n + (i - j)] *= d[i];
			else ans[i - j] *= d[i];
		}
	}
	int sum = 0;
	for(int i = 0; i < ans.size(); ++i)
		sum += ans[i];

	for(int i = 0; i < q; ++i) {
		scanf("%d", &a);
		int t = 0;
		for(int j = 4; j > 0; --j) {
			if(a - j < 0) {
				ans[n + (a - j)] *= -1;
				t += ans[n + (a - j)];
			} else {
				ans[a - j] *= -1;
				t += ans[a - j];
			}
		}
		sum += (t * 2);
		printf("%d\n", sum);
	}
}

//어떻게 풀었는지 기억안난다.
//단순 구현문제이니 기억 안나면 다시 풀어보자.