#include <bits/stdc++.h>
using namespace std;
int tc, h, w, g;
int main() {
	cin >> tc;
	while(tc--) {
		cin >> h >> w >> g;
		for(int i = 1; ; ++i) {
			if(h * 1 >= g) {
				cout << g * 100 + i << '\n';
				break;
			}
			g -= h * 1;
		}
	}
}

//»ý·«