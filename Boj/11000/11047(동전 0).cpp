#include <bits/stdc++.h>
using namespace std;
int n, m, ans, a;
vector<int> vec;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a);
		vec.push_back(a);
	}

	for(int i = vec.size() - 1; i >= 0; --i) {
		if(vec[i] <= m) {
			ans += (m / vec[i]);
			m %= vec[i];
		}
	}
	printf("%d\n", ans);
}

//설명
//문제를 잘 보면 A[i] = A[i-1]의 배수 라는 조건이 있다.
//이를 토대로 현실기준 명제를 세워보면
//동전의 개수를 최소로 하면서 물건을 지불하려면? 
//10원과 100원의 동전의 개수는 4개 이하를, 50원은 1개 이하 사용해야한다.
//
//이를 귀류법으로 증명해보면, 10원짜리가 5개가 되면 50원짜리 1개로 대체된다는
//간단한 예제를 들 수 있다.
//
//그럼 문제로 돌아와서, 정당성은 위에서 설명했으니 K원을 만들기 위해선
//가장 큰 값부터 빼가면 되는것이다.