#include <bits/stdc++.h>
using namespace std;
int d[int(1e4)+1];
int n, k;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> d[i];

	// 우선 집중국의 좌표가 무작위로 주어지니 오름차순으로 정렬한다.
	sort(d, d + n);

	// 집중국 간의 거리를 구한다.
	// ans는 제일 좌측과 제일 우측에 위치하는 센서간의 거리다.
	int ans = d[n - 1] - d[0];
	for(int i = n - 1; i > 0; --i)
		d[i] -= d[i - 1];
	
	// 센서간의 거리를 내림차순으로 정렬한 다음.
	sort(d, d + n, [](int a, int b){
		return a > b;
	});

	// K개 만큼 집중국을 세운다.
	for(int i = 0; i < n - 1; ++i){
		if(i == k - 1) break;
		ans -= d[i];
	}

	printf("%d\n", ans);
}

// 설명
// N개의 센서에 K개의 집중국을 설치해서 집중국들이 커버해야 되는 범위를 최소화 하는 문제이다.