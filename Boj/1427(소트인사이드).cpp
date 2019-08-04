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

//간단하게 문자열로 정렬하자.