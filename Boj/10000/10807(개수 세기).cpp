#include <bits/stdc++.h>
using namespace std;
int d[101];
int n, a, cnt;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &d[i]);
	}

	scanf("%d", &a);
	for(int i = 0; i < n; ++i){
		if(d[i] == a)
			cnt++;
	}
	printf("%d\n", cnt);
}

// 생략