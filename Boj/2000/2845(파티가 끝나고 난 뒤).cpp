#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main(){
	scanf("%d%d", &n, &m);
	n *= m;
	for(int i = 0; i < 5; ++i){
		scanf("%d", &k);
		printf("%d ", k - n);
	}
}

// 말하지 않아도 알아요~~