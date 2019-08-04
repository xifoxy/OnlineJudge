#include <bits/stdc++.h>
using namespace std;
long long sum = 1;
int n, i;
int main() {
	sum = 1;
	cin >> n;
	for(i = 1; sum < n; ++i) {
		sum = sum + (i * 6);
	}
	cout << i << '\n';
}

//문제에 나오는 벌집의 구조를 잘 살펴보면 6의 배수로 증가한다.
//6을 가지고 놀면된다.