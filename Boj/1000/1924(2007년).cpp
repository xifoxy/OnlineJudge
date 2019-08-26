#include <bits/stdc++.h>
using namespace std;
string day[]{"SUN","MON","TUE","WED","THU","FRI","SAT"};
int dd[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
	int m, d, a = 0;
	cin >> m >> d;
	for(int i = 0; i < m - 1; ++i)
		a += dd[i];
	a += d;
	cout << (a % 7 == 0 ? day[0] : day[a % 7]) << '\n';
}

// »ý·«