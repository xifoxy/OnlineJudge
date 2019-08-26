#include <bits/stdc++.h>
using namespace std;
string str;
stack<char> st;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);	
	cin >> str >> n;
	for(int i = 0; i < n; ++i) {
		char ch;
		cin >> ch;
		if(ch == 'B' && str.size()) str.pop_back();
		else if(ch == 'D' && st.size() != 0) {
			str.push_back(st.top());
			st.pop();
		} else if(ch == 'L' && str.size() != 0) {
			st.push(str.back());
			str.pop_back();
		} else if(ch == 'P') {
			cin >> ch;
			str.push_back(ch);
		}
	}
	while(st.size() != 0) {
		str.push_back(st.top());
		st.pop();
	}
	cout << str;
}

// ����(Stack)
// ���� �ΰ��� �̿��Ͽ� Ǭ �����̴�.
// ���� ���ϰ� ����ϱ� ���� �����ϳ��� stringŬ������ ��ü �ߴ�.
// Ŀ���� ������������ ��Ȳ�� �����ϱ� ���� ������ �ΰ� �̿��� ���̴�
// ������ �ѹ� �����غ���.