#include <iostream>
using namespace std;
int n, ans;
void divide(int x) {
	while((x /= 5) % 5 == 0) ans++;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i += 5)
		if(i % 5 == 0)
			divide(i * 5);
	cout << ans;
}

// 설명
// 우선 곱해서 0이 되는 수를 생각 해볼 필요가 있다.
// 5*2, 10*N, 15*4 .. 25*2
// 여기서 공통점은 5와 2가 만나면 0이 하나씩 추가된다는 것이다.
// 그럼 다시 돌아와서 2와 5를 다 카운팅 해야 하는가?
// 그건 아니다, 이유는 5의 개수보다 2의 개수가 훨씬 많기 때문이다.
// 곱셈의 결합법칙과 분배법칙에 의한거니 기초 수학을 공부하자.