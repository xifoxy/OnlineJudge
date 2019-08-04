#include <bits/stdc++.h>
using namespace std;
int t, i, a, b;
int main() {
	scanf("%d", &t);
	for(; i < t; ++i) {
		scanf("%d%d", &a, &b);
		if(a > b) printf("#%d >\n", i + 1);
		else if(a == b) printf("#%d =\n", i + 1);
		else printf("#%d <\n", i + 1);
	}
}