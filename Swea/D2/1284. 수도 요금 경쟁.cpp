#include <bits/stdc++.h>
int t, p, q, r, s, w, i;
int main() {
	scanf("%d", &t);
	for(; i < t; ++i) {
		scanf("%d%d%d%d%d", &p, &q, &r, &s, &w);
		if(r < w) q += (w - r) * s;
		printf("#%d %d\n", i + 1, std::min(q, p*w));
	}
}

//»ý·«