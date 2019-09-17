#include <bits/stdc++.h>
using namespace std;
int n;
// 앞에서 부터 검사하려면 0 때문에 수식이 더 보기 싫어진다.
bool safe(string &str) {
	int len = str.size();
	for(int i = 1; i <= len / 2; ++i) {
		if(str.substr(len - i, i) == str.substr(len - i * 2, i))
			return false;
	}
	return true;
}
void dfs(string &ans) {
	if(safe(ans) == false) return;
	if(ans.size() == n) {
		cout << ans << '\n';
		exit(0);
	}
	for(int i = 1; i <= 3; ++i) {
		ans.push_back((i + '0'));
		dfs(ans);
		ans.pop_back();
	}
}

int main() {
	string ans = "";
	cin >> n;
	dfs(ans);
}

// 설명(Backtracking)
// 가장 작은수를 뽑아내려면 permutation을 이용하면 되고, 
// 매번 검사하기 때문에 앞에서부터 N길이 만큼 을 반으로 쪼갠걸 검사하면 된다.