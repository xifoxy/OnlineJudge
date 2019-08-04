#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str, ans = "";
	cin >> str;
	stack<char> st;
	for(int i = 0; i < str.size(); ++i) {
		if(str[i] == '(') st.push('(');
		else if(str[i] == ')') {
			while(st.top() != '(') {
				ans.push_back(st.top());
				st.pop();
			} st.pop();
		} else if(str[i] == '/' || str[i] == '*') {
			while(st.size() && (st.top() == '/' || st.top() == '*')) {
				ans.push_back(st.top());
				st.pop();
			} st.push(str[i]);
		} else if(str[i] == '-' || str[i] == '+') {
			while(st.size() && st.top() != '(') {
				ans.push_back(st.top());
				st.pop();
			} st.push(str[i]);
		} else ans.push_back(str[i]);
	}
	while(st.size()) {
		ans.push_back(st.top());
		st.pop();
	}
	cout << ans;
}

//����
//�������̳� �켱������ �߿��� ������.
//ũ�� �ΰ��� �з��� ������ �ִµ�
//1. ��Ģ������ ���������
//2. ���� ��ȣ�� ������ ���

//�켱 ��ģ������ ������ ����̴�. 
//[1] = ���ϱ�, ������	[2] = ����, ���ϱ�
//[1]�� ������ �Ǹ� �Ǵٸ� [1]�� ���ö����� ���� ����� ��� �Ѵ�.
//A+B+C+D*A*B��� ��츦 �� �����غ���.
//[2]�� ��������쿡�� ������ȣ���� ���ο� �ΰ� ���� �ϼ����ָ� �ȴ�.

//���� ��ȣ�� ������ �Ǹ� ¦�� �Ǵ� ������ȣ���� ������ ���ָ�ȴ�.