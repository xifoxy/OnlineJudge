#include <bits/stdc++.h>
using namespace std;
int dp[10'000], cnt = 2;
char a;
int main() {
	dp[1111] = 1;
	string gg;
	for(int i = 1112; i <= 9999; ++i) {
		int t = i;
		bool ans = true;
		while(t > 0) {
			if(t % 10 == 0) ans = false;
			t /= 10;
		}
		if(!ans || dp[i]) continue;
		dp[i] = cnt;
		gg = to_string(i);
		for(int j = 0; j < 3; ++j) {
			gg = gg[3] + gg;
			gg.pop_back();
			dp[stoi(gg)] = cnt;
		}
		cnt++;
	}
	gg = "";
	for(int i = 0; i < 4; ++i) {
		cin >> a;
		gg.push_back(a);
	}
	cout << dp[stoi(gg)] << '\n';
}

// ����(Brute Force)

// ������ �ֱ� �����Ƽ� �׳� ���ڿ��� �̿��ߴ�.
// �켱 ����ó���� 0�� �� ���ڿ� �湮�ߴ� ���ڴ� �ɷ��ְ�
// ���ڸ� ���ۺ��� �������鼭 ��ȣ �ű�� �ȴ�.