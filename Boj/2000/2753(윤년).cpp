#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	if((n % 4 == 0 && n % 100) || n % 400 == 0)
		puts("1");
	else puts("0");
}

// 말하지 않아도 알아요~