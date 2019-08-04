#include <bits/stdc++.h>
using namespace std;
int tc;
int main() {
	cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a += c;
		b += d;
		if(b >= 60) a++, b %= 60;
		if(a > 12) a -= 12;
		printf("#%d %d %d\n", i, a, b);
	}
}

//»ý·«