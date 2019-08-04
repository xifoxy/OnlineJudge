#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int t = i;
		int cnt = 0;
		while(t > 0) {
			if(t % 10 == 3 || t % 10 == 6 || t % 10 == 9) cnt++;
			t /= 10;
		}
		if(cnt) for(int j = 0; j < cnt; ++j) printf("-");
		else cout << i;
		printf(" ");
	}
}

//»ý·«