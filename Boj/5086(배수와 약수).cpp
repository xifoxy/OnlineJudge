#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	while(scanf("%d%d", &a, &b)) {
		if(!a && !b) break;
		if(b % a == 0) puts("factor");
		else if(a / b * b == a) puts("multiple");
		else puts("neither");
	}
}

// 생략