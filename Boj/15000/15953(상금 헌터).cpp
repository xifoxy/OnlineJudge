#include <bits/stdc++.h>
using namespace std;
int prize7[6]{500,300,200,50,30,10};
int prize8[5]{512,256,128,64,32};
int d[6]{1,3,6,10,15,21};
int d2[5]{1,3,7,15,31};
int main() {
	int t, a, b;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &a, &b);
		int sum = 0;
		for(int i = 0; i < 6; ++i) {
			if(a <= d[i] && a) {
				sum += prize7[i];
				break;
			}
		}
		for(int i = 0; i < 5; ++i) {
			if(b <= d2[i] && b) {
				sum += prize8[i];
				break;
			}
		}
		printf("%d\n", sum * 10000);
	}
}

// 설명
// 이게 뭐라고 3번이나 틀렸다.