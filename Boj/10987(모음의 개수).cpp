#include <iostream>
#include <string>
using namespace std;
string s;
int ans;
int main() {
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		char t = s[i];
		if(t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u')
			ans++;
	}
	cout << ans;
}

//설명
//아에이오우