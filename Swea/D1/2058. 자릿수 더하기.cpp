#include <bits/stdc++.h>
using namespace std;
int a, s;
int main() {
	scanf("%d", &a); a *= 10;
	while(a /= 10)
		s += a % 10;
	printf("%d\n", s);
}

//»ý·«