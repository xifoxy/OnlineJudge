#include <bits/stdc++.h>
using namespace std;
int multiple, n;
int main(){
	scanf("%d",&multiple);
	while(scanf("%d", &n)){
		if(!n) break;
		if(n % multiple) printf("%d is NOT a multiple of %d.\n", n, multiple);
		else printf("%d is a multiple of %d.\n", n, multiple);
	}
}

// 생략