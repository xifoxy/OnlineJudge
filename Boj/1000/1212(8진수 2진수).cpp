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

// 설명(구현)
// 8진수에서 최대 나올수 있는 수는 7이다. 이걸 2진수화 해보면 111이다.
// 즉 8진수의 각 자릿수 마다 최대로 나올수 있는 길이는 3이라는 뜻이다.
// 첫째자리 숫자를 제외하곤 전부다 3자리를 만들어주면 된다.