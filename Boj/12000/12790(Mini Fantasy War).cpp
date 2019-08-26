#include <bits/stdc++.h>
using namespace std;
int tc;
int d[4];
int main() {
	scanf("%d", &tc);
	while(tc--) {
		int s;
		for(int i = 0; i < 4; ++i) scanf("%d", &d[i]);
		for(int i = 0; i < 4; ++i) {
			scanf("%d", &s);
			d[i] += s;
			if(d[i] <= 1 && (i == 0 || i == 1))
				d[i] = 1;
			if(d[i] < 0 && i == 2) d[i] = 0;
		}
		printf("%d\n", d[0] * 1 + d[1] * 5 + d[2] * 2 + d[3] * 2);
	}
}

// 생략