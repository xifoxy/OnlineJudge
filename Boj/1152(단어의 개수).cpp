#include <bits/stdc++.h>
using namespace std;
string in;
int main() {
	getline(cin, in);
	int idx = 0, ans = 0;
	while(idx < in.size()) {
		if(isalpha(in[idx]))
			ans++;
		while(idx < in.size() && in[idx++] != ' ');
	}
	cout << ans;
}

//설명
//우선 공백 문자를 입력받으려면 조금 다른 방식이 필요하다.
//나는 string을 선택했기때문에 getline을 이용했다.
//그리고 공백문자가 제일 처음 혹은 제일 마지막 그리고 두개이상 들어갈 경우를 생각해야한다.
//do while문을 쓰던가 아니면 나처럼 변태같은 조건을 집어넣든가.