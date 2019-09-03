#include <iostream>
#include <algorithm>
using namespace std;
int n, d[1000001];
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> d[i];
	sort(d, d + n);
	for(int i = 0; i < n; ++i)
		cout << d[i] << '\n';
}

// 말하지 않아도 알아요~