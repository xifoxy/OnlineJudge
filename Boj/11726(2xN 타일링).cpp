#include <iostream>
using namespace std;
int d[1001], n;
int main() {
	d[0] = d[1] = 1;
	cin >> n;
	for(int i = 2; i <= n; ++i)
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	cout << d[n];
}

//설명
//이친수와 01타일과 마찬가지로 같다.