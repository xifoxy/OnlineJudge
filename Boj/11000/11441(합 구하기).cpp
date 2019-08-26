#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 1;
int d[M], N;
int main(){
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		scanf("%d", &d[i]);
		d[i] += d[i-1];
	}

	int Query, st, ed;
	scanf("%d", &Query);
	for(int i = 0; i < Query; ++i){
		scanf("%d%d", &st, &ed);
		printf("%d\n", d[ed] - d[st - 1]);
	}
}

// 설명(Prefix Sum)
// 숫자의 변경이 없기 때문에 Prefix Sum을 이용하면 된다.