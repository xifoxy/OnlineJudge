#include <bits/stdc++.h>
using namespace std;
bool visit[31];
int main(){
	for(int i = 0; i < 28; ++i){
		int n;
		cin >> n;
		visit[n] = true;
	}
	for(int i = 1; i <= 30; ++i)
		if(!visit[i])
			cout << i << '\n';
}

// 생략