#include <bits/stdc++.h>
using namespace std;
struct info {
	int idx, sum = 0;
	int arr[3];
};
info d[3];
int n;

bool cmp(const info &a, const info &b) {
	if(a.sum == b.sum) {
		if(a.arr[2] == b.arr[2]) {
			return a.arr[1] == b.arr[1] ? a.arr[0] > b.arr[0] : a.arr[1] > b.arr[1];
		}
		return a.arr[2] > b.arr[2];
	}
	return a.sum > b.sum;
}

int main() {
	d[0].idx = 1, d[1].idx = 2, d[2].idx = 3;

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int a;
		for(int j = 1; j <= 3; ++j) {
			scanf("%d", &a);
			d[j - 1].arr[a - 1]++;
			d[j - 1].sum += a;
		}
	}

	sort(d, d + 3, cmp);
	if(d[0].sum == d[1].sum) {
		if(d[0].arr[2] == d[1].arr[2]) {
			if(d[0].arr[1] == d[1].arr[1]) {
				printf("%d ", d[0].arr[0] > d[1].arr[0] ? d[0].idx : 0);
			} else printf("%d ", d[0].idx);
		} else printf("%d ", d[0].idx);
	} else printf("%d ", d[0].idx);
	printf("%d\n", d[0].sum);
}

// 말하지 않아도 알아요~(너무 더럽다 수정필요)