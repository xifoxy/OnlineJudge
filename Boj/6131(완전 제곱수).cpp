#include <bits/stdc++.h>
using namespace std;
int n, ans, l, r;
int main() {
	vector<int> vec;
	vec.reserve(500);
	for(int i = 1; i <= 500; ++i)
		vec.push_back(i * i);

	cin >> n;
	while(r < 500) {
		if(vec[r] - vec[l] >= n) {
			if(vec[r] - vec[l] == n) ++ans;
			++l;
		} else ++r;
	}
	cout << ans;
}

//#�� ������

//���� ������ ���س��� �ε��� �����̸鼭 ���ϸ� �ȴ�.