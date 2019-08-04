#include <bits/stdc++.h>
using namespace std;
string a,b;
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		cin >> a >> b;
		cout << "Distances: ";
		for(int i = 0; i < a.size(); ++i){
			int dis = b[i] - a[i];
			if(dis < 0) dis += 26;
			cout << dis << ' ';
		}
		cout << '\n';
	}
}

// 생략