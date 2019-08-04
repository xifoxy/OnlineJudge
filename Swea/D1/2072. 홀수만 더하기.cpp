#include <bits/stdc++.h>
using namespace std;
int t, a;
int main() {
	scanf("%d", &t);
	for(int j = 0; j < t; ++j) {
		int sum = 0;
		for(int i = 0; i < 10; ++i) {
			scanf("%d", &a);
			if(a % 2 != 0)
				sum += a;
		}
		printf("#%d %d\n", j + 1, sum);
	}
}

//»ý·«