#include <bits/stdc++.h>
using namespace std;
int d[3];
int main(){
	cin >> d[0] >> d[1] >> d[2];
	sort(d, d + 3);
	string ans;
	cin >> ans;
	for(int i = 0; i < ans.size(); ++i){
		cout << d[ans[i] - 'A'] << ' ';
	}
}

// 말하지 않아도 알아요~