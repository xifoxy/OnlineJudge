#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str;
	stack<char> st;
	cin >> str;
	int mul = 1, ans = 0;
	for(int i = 0; i < str.size(); ++i) {
		if(str[i] == '(' || str[i] == '[') {
			st.push(str[i]);
			mul *= str[i] == '(' ? 2 : 3;
		}
		else if(st.size() == 0 || (str[i] == ')' && st.top() != '(') || (str[i] == ']' && st.top() != '[')) {
			ans = 0;
			break;
		} else {
			if(str[i - 1] == '[' || str[i - 1] == '(') ans += mul;
			st.pop();
			mul /= str[i] == ')' ? 2 : 3;
		}
	}
	cout << (st.size() ? 0 : ans);
}

//����
//���� ��ȣ�� ���� ������ �� ����Ϸ��� �ϸ� ������ ���� ���������.
//�׷��� �߻��� �ٲ㼭 ��ȣ�� �����븶�� ������ȣ�� ���������� �����ְ�
//���� ��ȣ�� ������ ó�����ָ� �ȴ�.

//���ذ� �ȵȴٸ�. �켱 �̰ͺ���..
//2 * (3 + 3) = (2 * 3) + (2 * 3)