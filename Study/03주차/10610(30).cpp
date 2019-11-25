#include <bits/stdc++.h>
using namespace std;
string num;
int n[10], sum;
int main(){
	cin >> num;
	for(int i = 0; i < num.size(); ++i){
		int idx = num[i] - '0';
		n[idx]++;
		sum += idx;
	}
	
	sort(num.begin(), num.end(), [](char a, char b){
		return a > b;
	});	

	if(!n[0] || sum % 3) cout << -1 << '\n';
	else cout << num;
}

// 설명
// https://ko.wikipedia.org/wiki/%EB%B0%B0%EC%88%98_%ED%8C%90%EC%A0%95%EB%B2%95
// 배수 판정법에 따르면,
// 3의 배수는 각 자리 숫자의 합이 3의 배수가 되어야 한다.
// 그럼 30배수니까 10으로 나누어 떨어지면서 3의 배수이면 된다.