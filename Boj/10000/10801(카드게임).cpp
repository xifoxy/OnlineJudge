#include <bits/stdc++.h>
using namespace std;
int d[10],d2[10],cnt;
int main(){
	for(int i = 0; i < 10; ++i)
		scanf("%d", &d[i]);
	for(int i = 0; i < 10; ++i){
		scanf("%d", &d2[i]);
		if(d[i] > d2[i]) cnt++;
		else if(d[i] < d2[i]) cnt--;
	}
	if(!cnt) puts("D");
	else printf("%c", cnt > 0 ? 'A' : 'B');
}

// 생략