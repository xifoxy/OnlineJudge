#include <bits/stdc++.h>
using namespace std;
int O, I, tc, a;
int main() {
	cin >> tc;
	while(tc--) {
		cin >> a;
		a ? I++ : O++;
	}
	cout << (I > O ? "Junhee is cute!" : "Junhee is not cute!");
}

//�̷��� ��Ǯ�� �ڻ��ؾߵȴ�.