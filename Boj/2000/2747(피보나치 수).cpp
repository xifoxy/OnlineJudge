#include <bits/stdc++.h>
using namespace std;
int d[50], n;
int main() {
	d[1] = d[2] = 1;
	cin >> n;
	for(int i = 3; i <= n; ++i)
		d[i] = d[i - 1] + d[i - 2];

	cout << d[n];
}

//»ý·«