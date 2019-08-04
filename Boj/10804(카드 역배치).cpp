#include <bits/stdc++.h>
using namespace std;
void query(int s, int e, vector<int> &orgin, vector<int> cpy) {
	for(int i = 0; i + s <= e; ++i) {
		orgin[i + s] = cpy[e - i];
	}
}
int main() {
	vector<int> vec(21);
	for(int i = 1; i <= 20; ++i)
		vec[i] = i;

	for(int i = 0; i < 10; ++i) {
		int s, e;
		scanf("%d%d", &s, &e);
		query(s, e, vec, vec);
	}

	for(int i = 1; i <= 20; ++i)
		printf("%d ", vec[i]);
	puts("");
}

// 설명
// 배열은 복사전달을 하려면 작업을 따로 해줘야된다
// 벡터는 편하니까 인자를 두개로 넘겨줘서 뒤집어주면된다

// 그런데 사실 reverse가 더 편하다.