#include <bits/stdc++.h>
using namespace std;
int d[26];
int main() {
	string str;
	cin >> str;
	for(int i = 0; i < str.size(); ++i) {
		d[str[i] - 'a']++;
	}
	for(int i = 0; i < 26; ++i)
		cout << d[i] << ' ';
}

//Ä«¿îÆÃ