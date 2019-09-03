#include <bits/stdc++.h>
using namespace std;
int d[3];
int main(){
	while(1){
		cin >> d[0] >> d[1] >> d[2];
		sort(d, d + 3);
		d[0] *= d[0];
		d[1] *= d[1];
		d[2] *= d[2];
		if(!d[0] && !d[1] && !d[2]) break;
		if(!d[0] || d[2] != d[1] + d[0]) cout << "wrong" << '\n';
		else cout << "right" << '\n';
	}
}

// 말하지 않아도 알아요~