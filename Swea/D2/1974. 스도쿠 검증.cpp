#include <bits/stdc++.h>
using namespace std;
int tc, d[9][9];
int main() {
	scanf("%d", &tc);
	for(int i = 1; i <= tc; ++i) {
		int x[9]{0,}, y[9]{0,}, z[9]{0,};
		bool ans = true;
		for(int j = 0; j < 9; ++j) {
			for(int k = 0; k < 9; ++k) {
				scanf("%d", &d[j][k]);
				x[j] |= (1 << d[j][k]);
				y[k] |= (1 << d[j][k]);
				z[(j / 3) * 3 + (k / 3)] |= (1 << d[j][k]);
			}
		}
		for(int j = 0; j < 9; ++j)
			if(x[j] != 1022 || y[j] != 1022 || z[j] != 1022)
				ans = false;
		printf("#%d ", i);
		if(ans) puts("1");
		else puts("0");
	}
}

//첨에 연산 제대로 못해서 개빡침