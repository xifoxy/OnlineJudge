#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int main() {
	cin >> s;
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	cout << s;
}

// 쉬어가는 문제