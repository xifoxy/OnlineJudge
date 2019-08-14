#include <bits/stdc++.h>
using namespace std;
string document, word;
int main() {
	getline(cin, document);
	getline(cin, word);
	int cnt = 0;

	for(int i = 0; i < document.size(); ++i) {
		if(document.substr(i, word.size()) == word) {
			i += word.size() - 1;
			cnt++;
		}
	}
	cout << cnt;
}

// 쉬어가는 문제