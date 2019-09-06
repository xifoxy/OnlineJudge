#include <bits/stdc++.h>
using namespace std;
int d[11], ans = 1e5;
int main(){
	for(int i = 1; i <= 10; ++i){
		scanf("%d", &d[i]);
		d[i] += d[i-1];
		if(abs(d[i] - 100) <= abs(100 - ans)){
			ans = d[i];
		}
	}
	printf("%d\n", ans);
}

// 말하지 않아도 알아요~