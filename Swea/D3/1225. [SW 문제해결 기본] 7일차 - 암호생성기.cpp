#include <bits/stdc++.h>
using namespace std;
int d[8], t, min_num;
int main() {
	for(int tc = 1; tc <= 10; ++tc) {
		min_num = 0x7fffffff;
		cin >> t;
		for(int i = 0; i < 8; ++i) {
			cin >> d[i];
			min_num = min(min_num, d[i]);
		}
		min_num = min_num / 15 - 1;
		int idx = 0, s = 1, pos = 10;
		if(min_num > 1) for(int i = 0; i < 8; ++i) {
			d[i] -= (min_num * 15);
			if(d[i] == 0)
				pos = i;
		}

		while(pos == 10) {
			d[idx++] -= s++;
			if(d[idx - 1] <= 0) {
				pos = idx - 1;
				break;
			}
			if(idx == 8) idx = 0;
			if(s == 6) s = 1;
		}
		idx = pos + 1 == 8 ? 0 : pos + 1;
		printf("#%d ", tc);
		while(idx != pos) {
			printf("%d ", d[idx++]);
			if(idx == 8) idx = 0;
		} puts("0");
	}
}

//»ý·«