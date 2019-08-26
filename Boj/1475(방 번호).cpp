#include <bits/stdc++.h>
using namespace std;
int d[10], mx;
string s;
int main() {
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		int num = s[i] - '0';
		d[num]++;
		if(num != 6 && num != 9)
			mx = max(d[num], mx);
	}
	int sn = d[6] + d[9];
	if(sn % 2 == 0) sn /= 2;
	else sn = sn / 2 + 1;
	cout << max(mx, sn);
}

// 설명
// 쉬운 문제이다. 6,9를 카운팅해서 계산하면 된다.