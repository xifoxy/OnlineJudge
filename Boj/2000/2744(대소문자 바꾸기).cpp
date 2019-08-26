#include <bits/stdc++.h>
using namespace std;
string str;
int main(){
	cin >> str;
	for(int i = 0; i < str.size(); ++i){
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		else str[i] -= 32;
	}
	cout << str;
}

// 쉬어가는 문제