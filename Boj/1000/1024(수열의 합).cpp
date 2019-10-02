#include <bits/stdc++.h>
using namespace std;
int num, len;
int main(){
	cin >> num >> len;
	
	for(; len <= 100; ++len){
		int sum = num - (len - 1) * len / 2;
		if(sum / len >= 0 && sum % len == 0){
			sum /= len;
			for(int i = sum; i < sum + len; ++i)
				cout << i << ' ';
			return 0;
		}
		
	}
	cout << -1;
}

// 일단 생략