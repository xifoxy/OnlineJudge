#include <bits/stdc++.h>
using namespace std;
string s, s1;
int main() {
	cin >> s >> s1;
	reverse(s.begin(), s.end());
	reverse(s1.begin(), s1.end());
	cout << max(stoi(s), stoi(s1));
}

// AH SAY~ 말하지 않아도 알아요~