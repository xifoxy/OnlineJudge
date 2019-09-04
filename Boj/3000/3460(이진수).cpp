#include <bits/stdc++.h>
using namespace std;
int n, tc;
void sol(int num, int idx){
	if(!num) return;
	if(num % 2) printf("%d ", idx);
	sol(num / 2, idx + 1);
}

int main(){
	scanf("%d", &tc);
	while(tc--){
		scanf("%d", &n);
		sol(n, 0);
		puts("");
	}
}

// 말하지 않아도 알아요~