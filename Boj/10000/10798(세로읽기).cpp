#include <bits/stdc++.h>
using namespace std;
string str[15], s;
int main() {
	for(int i = 0; i < 5; ++i) {
		cin >> s;
		for(int j = 0; j < s.size(); ++j) {
			str[j].push_back(s[j]);
		}
	}
	for(int i = 0; i < 15; ++i) {
		if(str[i].size())
			cout << str[i];
	}
}

//이런거 못풀면 자살해야된다.