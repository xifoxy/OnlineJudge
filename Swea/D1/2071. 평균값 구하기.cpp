#include <bits/stdc++.h>
using namespace std;
int t, a;
int main() {
	scanf("%d", &t);
	for(int j = 0; j < t; ++j) {
		double sum = 0;
		for(int i = 0; i < 10; ++i) {
			scanf("%d", &a);
			sum += a;
		}
		printf("#%d %d\n", j + 1, int(round(sum / 10)));
	}
}

//»ý·«