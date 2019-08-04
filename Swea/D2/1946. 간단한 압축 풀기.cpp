#include <bits/stdc++.h>
using namespace std;
int tc, n, a;
char ch;
int main() {
	cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		cin >> n;
		printf("#%d\n", i);
		for(int j = 0, idx = 0; j < n; ++j) {
			cin >> ch >> a;
			for(int k = 0; k < a; ++k) {
				printf("%c", ch);
				++idx;
				if(!(idx % 10)) puts("");
			}
		}
		puts("");
	}
}

//»ý·«