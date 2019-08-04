#include <bits/stdc++.h>
using namespace std;
bool d[10001];
void sol() {
	for(int i = 1; i <= 10000; ++i) {
		int t = i, sum = i;
		while(t > 0) {
			sum += (t % 10);
			t /= 10;
		}
		d[sum] = true;
	}
}
int main() {
	sol();
	for(int i = 1; i <= 10000; ++i)
		if(!d[i]) cout << i << '\n';
}

//알고리즘 처음접할때 풀었던 문제를 이제서야 다시 풀어본다.
//한때 넥슨 시험문제 였다는게 기억에 있는 문제다.