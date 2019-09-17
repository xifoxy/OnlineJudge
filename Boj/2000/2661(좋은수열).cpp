#include <bits/stdc++.h>
using namespace std;
int n;
// �տ��� ���� �˻��Ϸ��� 0 ������ ������ �� ���� �Ⱦ�����.
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

// ����(Backtracking)
// ���� �������� �̾Ƴ����� permutation�� �̿��ϸ� �ǰ�, 
// �Ź� �˻��ϱ� ������ �տ������� N���� ��ŭ �� ������ �ɰ��� �˻��ϸ� �ȴ�.