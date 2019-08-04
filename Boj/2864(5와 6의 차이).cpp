#include <iostream>
#include <string>
using namespace std;
int ret(string &a, string &b, char s) {
	for(int i = 0; i < a.size(); ++i)
		if(a[i] == '5' || a[i] == '6')
			a[i] = s;
	for(int i = 0; i < b.size(); ++i)
		if(b[i] == '5' || b[i] == '6')
			b[i] = s;
	return stoi(a) + stoi(b);
}
int main() {
	string a, b;
	cin >> a >> b;
	cout << ret(a, b, '5') << ' ' << ret(a, b, '6');
}

//설명
//문제 그대로 5는 6으로 6은 5로 바꿔서 계산하면 된다.