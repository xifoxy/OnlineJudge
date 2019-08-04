#include <bits/stdc++.h>
using namespace std;
deque<int> dq;
int t, a;
int main() {
	scanf("%d", &t);
	while(t--) {
		char cmd[15];
		scanf("%s", &cmd);
		if(cmd[1] == 'u') {
			scanf("%d", &a);
			cmd[5] == 'f' ? dq.push_front(a) : dq.push_back(a);
		} else if(cmd[1] == 'o') {
			if(dq.size()) {
				printf("%d\n", cmd[4] == 'f' ? dq.front() : dq.back());
				cmd[4] == 'f' ? dq.pop_front() : dq.pop_back();
			} else puts("-1");
		} 
		else if(cmd[0] == 'e') printf("%d\n", dq.size() ? 0 : 1);
		else if(cmd[0] == 'f') printf("%d\n", dq.size() ? dq.front() : -1);
		else if(cmd[0] == 'b') printf("%d\n", dq.size() ? dq.back() : -1);
		else printf("%d\n", dq.size());
	}
}

//»ý·«