#include <bits/stdc++.h>
using namespace std;
const int MX = 16;
char pass[MX];
int n, m;
void backt(int pos, string &print, int aeiou, int other) {
	if(print.size() == n) {
		if(aeiou >= 1 && other >= 2)
			cout << print << '\n';
		return;
	}

	for(int i = pos; i < m; ++i) {
		char t = pass[i];
		print.push_back(t);
		if(t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u')
			backt(i + 1, print, aeiou + 1, other);
		else backt(i + 1, print, aeiou, other + 1);
		print.pop_back();
	}
}
int main() {
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
		cin >> pass[i];

	sort(pass, pass + m);
	string print = "";
	backt(0, print, 0, 0);
}

//설명
//문제를 잘 읽어보면 N글자로 이루어진 암호속에 모음 >= 1 && 자음 >= 2
//라는 조건이 있다. 이것만 잘 지키면 문제 없을것 같다.