#include <bits/stdc++.h>
using namespace std;
int d[10001], n, m, start, interval, cnt;
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &start, &interval);
		for(int pos = start; pos <= n; pos += interval) {
			if(!d[pos]) {
				cnt++;
				d[pos] = 1;
			}
		}
	}
	printf("%d\n", n - cnt);
}

//이런거 못풀면 자살해야된다.