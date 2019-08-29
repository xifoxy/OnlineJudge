#include <bits/stdc++.h>
using namespace std;
const int MXD = 1e5 + 1;
int n, k;
int d[MXD];
int main() {
	scanf("%d%d", &n, &k);
	vector<int> coin; coin.reserve(n);
	for(int i = 0; i < n; ++i) {
		int num;
		scanf("%d", &num);
		coin.push_back(num);
	}

	sort(coin.begin(), coin.end());
	for(int now = 0; now < coin.size(); ++now) {
		d[coin[now]] = 1;
		for(int next = coin[now]; next <= k; ++next) {
			int pos = next - coin[now];
			if(pos > 0 && d[pos]) {
				d[next] = d[next] == 0 ? d[pos] + 1 : min(d[pos] + 1, d[next]);
			}
		}
	}
	printf("%d\n", d[k] == 0 ? -1 : d[k]);
}

// 설명(DP)
// 2293 동전 2문제와 같다. 단, 대소 관계를 이용해 DP를 갱신해줘야한다.