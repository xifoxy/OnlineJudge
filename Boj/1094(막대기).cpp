#include <bits/stdc++.h>
using namespace std;
int x, n, cnt, devide;
int main() {
	x = 64;
	cin >> n;
	while(n <= x + devide) {
		if(n == x) break;
		if(x > n) {
			x /= 2;
			devide = x;
		} else {
			devide /= 2;
			if(devide + x <= n) {
				cnt++;
				x += devide;
			}
		}
	}
	cout << cnt + 1;
}

// 그냥 수학