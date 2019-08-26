#include <iostream>
#include <string>
using namespace std;
string s;
int main() {
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		s[i] -= 3;
		if(s[i] < 'A')
			s[i] = 'Z' - 'A' + s[i] + 1;
	}
	cout << s;
}

//설명
//간단한 문자구현이다. A보다 작을때만 유의하면된다.