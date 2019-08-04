#include <bits/stdc++.h>
using namespace std;
int tc, n;
int money[8]{50000,10000,5000,1000,500,100,50,10};
int d[8];

int main() {
	cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		memset(d, 0, sizeof(d));
		cin >> n;
		int j = 0;
		while(n > 0) {
			if(n >= money[j]) {
				d[j]++;
				n -= money[j];
			} else ++j;
		}
		printf("#%d\n", i);
		for(int k = 0; k < 8; ++k)
			printf("%d ", d[k]);
		puts("");
	}
}

//»ý·«