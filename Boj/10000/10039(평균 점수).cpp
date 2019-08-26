#include <bits/stdc++.h>
using namespace std;
int sum, a;
int main() {
	for(int i = 0; i < 5; ++i)
		cin >> a, sum += (a <= 40 ? 40 : a);
	cout << sum / 5;
}

//»ý·«