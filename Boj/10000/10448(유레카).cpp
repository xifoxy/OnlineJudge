#include <bits/stdc++.h>
using namespace std;
int ans[1001];
vector<int> d;
int main() {
	int seq = 1;
	d.push_back(seq);
	for(int i = 1; ; ++i) {
		d.push_back(d[i - 1] + ++seq);
		if(d[i] > 1000) break;
	}

	int sz = d.size();
	for(int i = 0; i < sz; ++i) {
		for(int j = 0; j < sz; ++j) {
			for(int k = 0; k < sz; ++k) {
				int sum = d[i] + d[j] + d[k];
				if(sum > 1000) break;
				ans[sum] = 1;
			}
		}
	}
	int n, a;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &a);
		printf("%d\n", ans[a]);
	}
}

//설명
//우선 문제를 풀기위해 삼각수의 원리를 알아야 한다.
//T(N) = T(N - 1) + N
//이를 구하고 나서 문제에서 요구하는 삼각수 3개 합들을 구하면 된다.