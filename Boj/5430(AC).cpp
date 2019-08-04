#include <bits/stdc++.h>
using namespace std;
int tc, l, r, a, n;
string order, num;
deque<int> st;

void init() {
	st.resize(n);
	string temp;
	for(int i = 1, idx = 0; i < num.size(); ++i) {
		if((num[i] == ',' || i == num.size() - 1) && temp.size()) {
			st[idx++] = stoi(temp);
			temp.clear();
		} else temp.push_back(num[i]);
	}
}

void sol() {
	bool isback = true;
	for(int i = 0; i < order.size(); ++i) {
		if(order[i] == 'R') isback = isback ? false : true;
		else {
			if(st.size() == 0) {
				puts("error");
				return;
			}
			if(isback) st.pop_front();
			else st.pop_back();
		}
	}
	printf("[");
	int sz = st.size();
	if(isback) {
		for(int i = 0; i < sz; ++i)
			if(i == sz - 1) printf("%d", st[i]);
			else printf("%d,", st[i]);
	} else {
		for(int i = sz - 1; i >= 0; --i)
			if(i == 0) printf("%d", st[i]);
			else printf("%d,", st[i]);
	}
	printf("]\n");
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> tc;
	while(tc--) {
		cin >> order >> n >> num;
		init();
		sol();
	}
}

//설명
//주어진 배열의 원소 x가 1 <= xi <= 100 이라는걸 읽지않고 풀었다가 된통 당했다.