#include <bits/stdc++.h>
using namespace std;
int a, s = 2;
int main() {
	cin >> a;
	while(a > 1) {
		if(a % s) s++;
		else {
			cout << s << '\n';
			a /= s;
		}
	}
}

//이런거 못풀면 자살해야된다.