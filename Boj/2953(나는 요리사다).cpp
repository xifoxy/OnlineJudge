#include <bits/stdc++.h>
using namespace std;
int ans, idx, sum, a;
int main() {
	for(int i = 0; i < 5; ++i) {
		sum = 0;
		for(int j = 0; j < 4; ++j) {
			cin >> a;
			sum += a;
		}
		if(ans < sum) ans = sum, idx = i + 1;
	}
	cout << idx << ' ' << ans;
}

//�̷��� ��Ǯ�� �ڻ��ؾߵȴ�.