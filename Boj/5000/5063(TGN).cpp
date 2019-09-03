#include <bits/stdc++.h>
using namespace std;
int r,e,c,n;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d%d",&r,&e,&c);
		if(r == e - c) puts("does not matter");
		else if(r > e - c) puts("do not advertise");
		else puts("advertise");
	}
}

// 말하지 않아도 알아요~