#include <iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	for(int i = 1; ; ++i) {
		if(n <= i) {
			if(i % 2) cout << i - n + 1 << '/' << n << '\n';
			else cout << n << '/' << i - n + 1 << '\n';
			break;
		}
		n -= i;
	}
}

//구조자체가 등차수열을 이루고 있다.
//뒤집어서 생각해보면 index = n의 포함된 횡은
//등차수열의 1씩 증가하는 등차수열을 빼다보면 나오는 횡이 된다.
//홀수일때는 내려오고 짝수일때는 내려가니
//횡을 구하고 남은 숫자는 짝수일때 분자가 홀수일때 분모가 된다.