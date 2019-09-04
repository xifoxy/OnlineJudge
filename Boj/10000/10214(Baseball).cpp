#include <bits/stdc++.h>
using namespace std;
int tc, a, b;
int main(){
	cin >> tc;
	while(tc--){
		int Y = 0, G = 0;
		for(int i = 0; i < 9; ++i){
			cin >> a >> b;
			Y += a;
			G += b;
		}
		if(Y == G) cout << "Draw" << '\n';
		else cout << (Y > G ? "Yonsei" : "Korea") << '\n';
	}
}

// 말하지 않아도 알아요~