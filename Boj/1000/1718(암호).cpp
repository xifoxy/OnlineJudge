#include <bits/stdc++.h>
using namespace std;
string pass, text;
int main() {
	getline(cin, pass);
	getline(cin, text);
	
	int pos = 0;
	for(int cur = 0; cur < pass.size(); ++cur, ++pos) {
		if(pos == text.size())
			pos = 0;
		if(pass[cur] == ' ') continue;
		int next = text[pos] - 'a' + 1;
		next = pass[cur] - next;
		pass[cur] = next < 'a' ? 'z' - ('a' - next - 1) : next;
	}
	cout << pass << '\n';
}

// ¹®ÀÚ¿­ ³îÀÌ