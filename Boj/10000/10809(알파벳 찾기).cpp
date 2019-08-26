#include <bits/stdc++.h>
using namespace std;
int d[26];
int main() {
	string str;
	cin >> str;
	memset(d, -1, sizeof(d));
	for(int i = 0; i < str.size(); ++i) {
		int idx = str[i] - 'a';
		if(d[idx] == -1) d[idx] = i;
	}
	for(int i = 0; i < 26; ++i)
		cout << d[i] << ' ';
}

//설명
//저장배열의 값이 -1일 때만 갱신하면 된다.