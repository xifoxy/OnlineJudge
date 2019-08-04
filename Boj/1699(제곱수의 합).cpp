#include <bits/stdc++.h>
using namespace std;
int n, d[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= 100000; ++i) {
		for(int j = 1; j * j <= i; ++j) {
			if(d[i] > d[i - j * j] + 1 || !d[i])
				d[i] = d[i - j * j] + 1;
		}
	}
	cout << d[n];
}

//설명
//소스 보자.
//생략