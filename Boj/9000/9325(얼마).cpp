#include <bits/stdc++.h>
using namespace std;
int tc;
int main(){
	cin >> tc;
	while(tc--){
		int op, s, a, b;
		cin >> s;
		cin >> op;
		while(op--){
			cin >> a >> b;
			s += (a * b);
		}
		cout << s << '\n';
	}
}

// ������ �ʾƵ� �˾ƿ�~