#include <bits/stdc++.h>
using namespace std;
string in;
int main() {
	getline(cin, in);
	int idx = 0, ans = 0;
	while(idx < in.size()) {
		if(isalpha(in[idx]))
			ans++;
		while(idx < in.size() && in[idx++] != ' ');
	}
	cout << ans;
}

// 설명
// 문자열을 통짜로 받을 필요가 있다.
// string 클래스는 공백을 기준으로 끊어 받기 때문에 getline함수를 써야 한다.