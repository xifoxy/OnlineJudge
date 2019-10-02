#include <bits/stdc++.h>
using namespace std;
string str;
int alpha_cnt[10], sum;
int main(){
	cin >> str;
	for(int i = 0; i < str.size(); ++i){
		sum += str[i] - '0';
		alpha_cnt[str[i] - '0']++;
	}

	if(sum % 3 != 0 || !alpha_cnt[0]) cout << -1 << '\n';
	else {
		sort(str.begin(), str.end());
		reverse(str.begin(), str.end());
	}
}

// 설명(Sort)
// 30의 배수가 되기 위한 조건은 뭐가 있을까?
// 결론은 3의 배수와 10의 배수로 조건을 나누면 된다.
// 그러니까 0이 하나라도 존재해야 하고, 3의 배수가 되려면 각 자릿수들을 다 더했을때
// 3으로 나뉘어져야 한다.