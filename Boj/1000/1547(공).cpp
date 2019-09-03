#include <bits/stdc++.h>
using namespace std;
int n, ball = 1;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		if(a == ball) ball = b;
		else if(b == ball) ball = a;
	}
	printf("%d\n", ball);
}

// 말하지 않아도 알아요~