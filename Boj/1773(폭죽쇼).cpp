#include <bits/stdc++.h>
using namespace std;
bool d[2'000'001];
int n, m, a, ans;
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		for(int start = a; start <= m; start += a) {
			if(!d[start]) {
				ans++;
				d[start] = true;
			}
		}
	}
	cout << ans;
}

//�̷��� ��Ǯ�� �ڻ��ؾߵȴ�.