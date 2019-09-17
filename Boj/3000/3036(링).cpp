#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	return a % b ? gcd(b, a % b) : b;
}
int main(){
	int n, d, a;
	scanf("%d%d", &n, &d);
	for(int i = 1; i < n; ++i){
		scanf("%d", &a);
		printf("%d/%d\n", d / gcd(a,d), a / gcd(a,d));
	}
}

// 설명(GCD) 생략