#include <bits/stdc++.h>
using namespace std;
int d[9];
int main() {
	for(int i = 0; i < 8; ++i)
		cin >> d[i];
	bool as = true, de = true;
	for(int i = 0; i < 8; ++i) {
		if(d[i] != i + 1) as = false;
		if(d[i] != 8 - i) de = false;
	}
	if(as) puts("ascending");
	else if(de) puts("descending");
	else puts("mixed");
}

//우아하게 짤 생각하지말자