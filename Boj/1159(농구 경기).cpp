#include <bits/stdc++.h>
using namespace std;
int d[26], n;
int main() {
	string name, ans;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> name;
		d[name[0] - 'a']++;
	}

	for(int i = 0; i < 26; ++i) if(d[i] >= 5) {
		ans.push_back('a' + i);
	}
	if(ans.size()) cout << ans;
	else cout << "PREDAJA";
}

// 설명
// 어렵게 생각할 필요 없이 각 이름의 첫번째 글자만 메모 해두면 된다.