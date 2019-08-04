#include <bits/stdc++.h>
using namespace std;
const int MX = 2000001;
int arr[MX], n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n + m; ++i)
		scanf("%d", &arr[i]);

	int left = 0, right = n;
	while(left < n && right < m + n) {
		printf("%d ", arr[left] < arr[right] ? arr[left++] : arr[right++]);
	}
	while(left < n)
		printf("%d ", arr[left++]);
	while(right < m + n)
		printf("%d ", arr[right++]);
}

//설명
//정렬된 배열이기에 병합정렬의 분할부가 아닌 병합부분을 응용하면된다.
//좀더 빠르게 하려면 fastio를 쓰자.