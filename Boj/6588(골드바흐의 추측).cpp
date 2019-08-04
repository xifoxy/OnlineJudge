#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int n;
bool d[MAX + 1];
int main() {
	vector<int> isprime;
	for(int i = 2; i*i <= MAX; ++i) {
		if(d[i]) continue;
		for(int j = i * i; j <= MAX; j += i)
			d[j] = true;
	}
	
	while(scanf("%d", &n) && n != 0) {
		for(int i = 3; ; i += 2) {
			if(!d[i] && !d[n - i]) {
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
	}
}

//증명이 안된 가정이지만 답은 무조건적으로 나오게 되어 있다.
//그러니까 완탐으로 답이 나올때까지 돌리면 된다.