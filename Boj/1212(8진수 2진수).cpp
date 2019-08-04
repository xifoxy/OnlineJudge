#include <iostream>
#include <string>
using namespace std;
string in, ans, temp;
void sol(int n) {
	if(n == 0) return;
	char t = n % 2 + '0';
	temp = t + temp;
	sol(n / 2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> in;
	if(in[0] == '0') ans = '0';
	else for(int i = 0; i < in.size(); ++i) {
		temp = "";
		sol(in[i] - '0');
		if(i != 0 && temp.size() < 3) {
			for(int i = temp.size(); i < 3; ++i)
				temp = '0' + temp;
		}
		ans += temp;
	}
	cout << ans << '\n';
}

//설명
//나는 문제를 각 자릿수 마다 비트를 카운트 하는법으로 해결했다.
//한가지 유의해야 할 사항은 각 자릿수마다 비트를 카운트해서 더하되,
//8진수의 경우 2진화시 자릿수마다 최대 3자리까지 나와야 한다.
//첫 자리만 제외하고 3자리가 안되면 그만큼 0을 더해줘서 해결한다.
//기저사례로 0일때는 무조건 0을 출력한다 라는 조건을 넣지 않으면 오답처리가 되니 주의하자.