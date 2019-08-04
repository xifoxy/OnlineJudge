#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, cmd, a;
int board[20][20], dx[]{0,0,-1,1}, dy[]{1,-1,0,0};
deque<int> dice(4, 0), wing(2, 0);
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
void cpy(const int nx, const int ny) {
	if(!board[nx][ny]) board[nx][ny] = dice[1];
	else {
		dice[1] = board[nx][ny];
		board[nx][ny] = 0;
	}
}
void NH(int &nx, int &ny) {
	int t;
	if(!safe(nx + dx[a], ny + dy[a])) return;
	if(a == 2) {
		t = dice.back();
		dice.pop_back();
		dice.push_front(t);
	} else {
		t = dice.front();
		dice.pop_front();
		dice.push_back(t);
	}
	nx += dx[a]; ny += dy[a];
	cpy(nx, ny);
	printf("%d\n", dice[3]);
}
void EW(int &nx, int &ny) {
	int t = wing[0], t2 = wing[1];
	if(!safe(nx + dx[a], ny + dy[a])) return;
	if(a == 0) {
		swap(dice[1], wing[0]);
		dice[1] = t2;
		swap(dice[3], wing[1]);
		dice[3] = t;
	} else {
		swap(dice[1], wing[1]);
		dice[1] = t;
		swap(dice[3], wing[0]);
		dice[3] = t2;
	}
	nx += dx[a]; ny += dy[a];
	cpy(nx, ny);
	printf("%d\n", dice[3]);
}
int main() {
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &cmd);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);
	}
	for(int i = 0; i < cmd; ++i) {
		scanf("%d", &a);
		a--;
		if(a > 1) NH(x, y);
		else EW(x, y);
	}
}

#include <bits/stdc++.h>
using namespace std;
int dice[6], n, m, c, x, y, cmd;
int dx[]{0,0,-1,1}, dy[]{1,-1,0,0};
int d[21][21];
int dir[4][3]{{3,1,4},{4,1,3},{2,1,5},{5,1,2}};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 & x < n && y < m;
}
int main() {
	cin >> n >> m >> x >> y >> c;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> d[i][j];

	for(int i = 0; i < c; ++i) {
		cin >> cmd; --cmd;
		int nx = x + dx[cmd];
		int ny = y + dy[cmd];
		if(!safe(nx, ny)) continue;
		int temp = dice[0];
		dice[0] = dice[dir[cmd][0]];
		dice[dir[cmd][0]] = dice[dir[cmd][1]];
		dice[dir[cmd][1]] = dice[dir[cmd][2]];
		dice[dir[cmd][2]] = temp;
		x = nx; y = ny;
		if(!d[x][y]) d[x][y] = dice[1];
		else {
			dice[1] = d[x][y];
			d[x][y] = 0;
		}
		cout << dice[0] << '\n';
	}
}

//설명
//쉬운문제다. 4가지의 방향전환을 직접 손으로 그려보면 바로 답이 나온다.
//나는 뒤에 숫자를 앞으로 보내거나 혹은 앞에 있는 숫자를 앞으로 보내기 쉽게 하기 위해
//덱을 이용했다.
//그리고 이 그지같은 시뮬레이션은 조건을 항상 잘 읽고 그대로 구현하는 연습을 해야한다.

//조금더 짧은 소스로 만들어봤다.
// 1     0
//010   111
// 1     0
// 1     1
//주사위 값의 변화는 저 두가지로 나뉜다.(1이라고 표시된 위치만)
//저기서 매번 바뀌는 값은 바닥을 보는쪽과 천장을 보는쪽이다.
//이를 토대로 방향값만 추출하면 먼저 작성했던 위의 소스처럼 더럽게 짤 필요가 없다.