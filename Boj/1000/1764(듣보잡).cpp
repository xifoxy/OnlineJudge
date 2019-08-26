#include <iostream>
#include <map>
#include <string>
using namespace std;
int n, m, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;
	string s;
	map<string, int> mp;
	for(int i = 0; i < n + m; ++i) {
		cin >> s;
		mp[s]++;
		if(mp[s] > 1)
			ans++;
	}
	cout << ans << '\n';
	for(auto &p : mp) {
		if(p.second > 1)
			cout << p.first << '\n';
	}
}

//설명
//정렬하기 귀찮으니까 정렬이 되는 map구조체를 쓰자.