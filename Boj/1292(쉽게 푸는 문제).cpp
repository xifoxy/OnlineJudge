#include <bits/stdc++.h>
int s, e, ans, c, l = 1;
int main() {
	scanf("%d%d", &s, &e);
	for(int i = 0; i < e; ++i, ++c) {
		if(c >= l)
			c = 0, ++l;
		if(i >= s - 1) ans += l;
	}
	printf("%d\n", ans);
}

// 그냥 구현