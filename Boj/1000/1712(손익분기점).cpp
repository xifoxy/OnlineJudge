#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
int main(){
	cin >> a >> b >> c;
	if(b >= c) cout << -1;
	else cout << a / (c - b) + 1;
}

// 설명(Math)
// 이 문제는 도대체 왜 정답률이 30프로 미만인지 모르겠다.
// 문제에 설명을 조금 꼬아놨는데,
// A는 신제품을 개발하는 비용이고, B는 제품을 만드는 비용이라고 생각하면 쉽다.
// B가 C보다 크거나 같으면 A비용을 상쇄시킬 수 없기 때문에 무조건 -1을 출력하고
// C가 큰 경우에만 한대를 팔았을대 생기는 이득율로 답을 도출하면된다.