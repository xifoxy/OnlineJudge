#include <bits/stdc++.h>
using namespace std;
int tc;
int n, d[5]{2,3,5,7,11};
int main() {
	cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		cin >> n;
		int j = 0;
		int ans[5]{};
		while(j < 5 && n > 0) {
			if(n % d[j]) ++j;
			else {
				ans[j]++;
				n /= d[j];
			}
		}
		printf("#%d ", i);
		for(int j = 0; j < 5; ++j)
			printf("%d ", ans[j]);
		puts("");
	}
}

//»ý·«