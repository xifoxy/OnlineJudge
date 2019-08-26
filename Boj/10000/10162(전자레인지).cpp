#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	if(n % 10) puts("-1");
	else {
		printf("%d ", n / 300);
		printf("%d ", (n %= 300) / 60);
		printf("%d", (n %= 60) / 10);
	}
}

// 왜 60프로가 안되는지 이해불가하다.