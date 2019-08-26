#include <bits/stdc++.h>
using namespace std;
int main() {
	string s; 
	getline(cin, s);

	size_t pos = 0;
	int happy = 0, sad = 0;
	while((pos = s.find(":-)", pos)) != string::npos) happy++, pos++;
	pos = 0;
	while((pos = s.find(":-(", pos)) != string::npos) sad++, pos++;

	if(!happy && !sad) puts("none");
	else if(happy == sad) puts("unsure");
	else if(happy > sad) puts("happy");
	else puts("sad");
}

// 설명
// 귀찮으니까 find랑 npos