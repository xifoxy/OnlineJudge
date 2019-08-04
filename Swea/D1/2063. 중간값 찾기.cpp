#include <bits/stdc++.h>
using namespace std;
int d[222], t, i;
int main() {
	scanf("%d", &t);
	for(; i < t; ++i)
		scanf("%d", &d[i]);
	sort(d, d + t);
	printf("%d\n", d[t / 2]);
}

//»ý·«