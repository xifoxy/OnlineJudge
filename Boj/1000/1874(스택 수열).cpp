#include <bits/stdc++.h>
using namespace std;
int n, a, d[100001], idx, num;
int main() {
	string ans = "";
	cin >> n;
	stack<int> st;
	for(int i = 0; i < n; ++i)
		cin >> d[i];


	while(idx < n) {
		// ���ÿ� N + 1 ���� ���ڰ� ���ų�,
		// ���� �ֻ�ܿ� �ִ� ���ڰ� ����ؾ��� ���ں��� ũ�ٸ� �Ұ����� ����.
		if(num > n || (st.size() && st.top() > d[idx])) break;

		// ���� ���� �ֻ�ܿ� �ִ� ���ڰ� ����ؾ� �� ���ڶ�� ���ÿ� �ִ� ���ڸ� �̾Ƴ���.
		if(st.size() && st.top() == d[idx]) {
			st.pop();
			ans.push_back('-');
			++idx;
		}
		// ������ ����ų�, ���û�ܿ� �ִ� ���ڰ� ����ؾ��� ���ں��� ũ�ٸ�
		// ���� ���ڸ� �ִ´�.
		else if(st.size() == 0 || (st.top() <= d[idx])) {
			st.push(++num);
			ans.push_back('+');
		}
	}
	if(st.size()) cout << "NO";
	else for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << '\n';
}

// ����(Stack)
// 1~N���� �־��� Input�� ������� ������ ����� �����̴�.
// �׸����� ������. ���ÿ� ���ڸ� ���������� �׾ư��ٰ� ����ؾ��� ���ڿ� ��ġ�Ѵٸ� �� ���ڸ� ���ָ� �ȴ�.