#include <bits/stdc++.h>
using namespace std;
int tc, n, d[1001], sum;
int main() {
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &n);
		sum = 0;
		for(int i = 0; i < n; ++i)
			scanf("%d", &d[i]), sum += d[i];

		double avg = 1.0 * sum / n;
		int cnt = 0;
		for(int i = 0; i < n; ++i)
			if(avg < d[i])
				cnt++;
		double percent = double(cnt) / n * 100;
		printf("%.3lf%%\n", percent);
	}
}

//»ý·«