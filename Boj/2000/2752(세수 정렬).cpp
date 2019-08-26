#include <bits/stdc++.h>
using namespace std;
int d[3];
int main(){
	cin >> d[0] >> d[1] >> d[2];
	sort(d, d + 3);
	cout << d[0] << ' '<< d[1] << ' ' << d[2];
}

//쉬어가는 문제