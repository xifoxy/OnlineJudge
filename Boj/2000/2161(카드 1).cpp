#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	queue<int> Q;
	for(int i = 1; i <= n; ++i)
		Q.push(i);

	while(!Q.empty()){
		printf("%d ", Q.front());
		Q.pop();
		if(Q.empty()) break;
		Q.push(Q.front());
		Q.pop();
	}
}

// 말하지 않아도 알아요~