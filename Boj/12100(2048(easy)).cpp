#include <bits/stdc++.h>
using namespace std;
int n;
int sol(vector<vector<int>> d, int cnt) {
	int ret = 0;
	if(cnt == 0) {
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				ret = max(ret, d[i][j]);
		return ret;
	}
	vector<vector<int>> org = d;
	for(int direction = 0; direction < 4; ++direction) {
		vector<int> temp;
		for(int x = 0; x < n; ++x) {
			temp.clear();
			for(int y = 0; y < n; ++y) {
				if(direction > 1 && d[y][x] != 0)
					temp.push_back(d[y][x]);
				else if(direction < 2 && d[x][y] != 0)
					temp.push_back(d[x][y]);
			}
			vector<int> temp2;
			if(direction == 1 || direction == 3) reverse(temp.begin(), temp.end());
			for(int i = 0; i < temp.size(); ++i) {
				if(i + 1 < temp.size() && temp[i + 1] == temp[i])
					temp2.push_back(temp[i] * 2), ++i;
				else temp2.push_back(temp[i]);
			}

			for(int i = temp2.size(); i < n; ++i)
				temp2.push_back(0);

			if(direction == 1 || direction == 3) reverse(temp.begin(), temp.end());
			for(int y = 0; y < n; ++y) {
				if(direction > 1)
					d[y][x] = temp2[y];
				else d[x][y] = temp2[y];
			}
		}
		ret = max(ret, sol(d, cnt - 1));
		d = org;
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	vector<vector<int>> d(n, vector<int>(n));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &d[i][j]);

	printf("%d\n", sol(d, 5));
}

//설명
//문제 : 감시, 주사위 굴리기, 미세먼지 등
//방향전환의 개념만 잘 이해한다면 이 문제 또한 어렵지 않게 해결할 수 있다.
//원본 배열을 저장해뒀다가 재귀에서 탈출할때 복구 시키는걸 잘 살펴보자.