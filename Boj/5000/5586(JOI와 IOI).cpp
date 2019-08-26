#include <bits/stdc++.h>
using namespace std;
string str;
int joi, ioi;
int main(){
	cin >> str;
	size_t pos = 0;
	while((pos = str.find("JOI", pos)) != string::npos) joi++, pos++;

	pos = 0;
	while((pos = str.find("IOI", pos)) != string::npos) ioi++, pos++;
	cout << joi << '\n' << ioi;
}

// 생략