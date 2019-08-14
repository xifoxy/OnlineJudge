#include <bits/stdc++.h>
using namespace std;
string hexademical;
int main() {
	int ans = 0;
	cin >> hexademical;
	for(int i = 0; i < hexademical.size(); ++i) {
		ans *= 16;
		if(hexademical[i] >= '0' && hexademical[i] <= '9')
			ans += (hexademical[i] - '0');
		else ans += (hexademical[i] - 'A' + 10);
	}
	cout << ans;
}

// 쉬어가는 문제