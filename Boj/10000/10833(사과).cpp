#include <bits/stdc++.h>
using namespace std;
int sum, a, b, n;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &a, &b);
		if(a > b) sum += b;
		else sum += (b % a);
	}
	printf("%d\n", sum);
}

// 말하지 않아도 알아요~