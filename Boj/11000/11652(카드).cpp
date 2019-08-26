#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, cnt;
ll idx = 4611686018427387904, a;
map<ll, int> mp;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		mp[a]++;
		if(cnt < mp[a]) {
			idx = a;
			cnt = mp[a];
		}
		if(idx != a && mp[a] == mp[idx])
			idx = min(a, idx);
	}
	cout << idx << '\n';
}

//설명
//쉬운문제인제 집중을 못해서 5번이나 틀렸다.
//입력 자체는 100만개 밖에 안되지만 범위는 위에 적어놓은
//-idx <= N <= idx 이기때문에 자료구조는 map으로 하면 적합하다.
//답은 가장 많이 중복입력된 수 이지만, 가장 작은 수 이니 조건문 작성에 유의하자.