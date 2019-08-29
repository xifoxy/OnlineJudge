#include <bits/stdc++.h>
using namespace std;
int tc, n, p, a;
struct P { int num, idx; };
int main() {
	scanf("%d", &tc);
	while(tc--) {
		deque<P> Q;
		vector<int> v;
		scanf("%d%d", &n, &p);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a);
			Q.push_back({a, i});
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		int idx = 0;
		while(1) {
			if(v.back() == Q.front().num) {
				++idx;
				v.pop_back();
				if(Q.front().idx == p) {
					printf("%d\n", idx);
					break;
				}
				Q.pop_front();
			} else {
				Q.push_back(Q.front());
				Q.pop_front();
			}
		}
	}
}

// 설명(Queue)
// 그냥 잘넣고 잘빼면 된다.