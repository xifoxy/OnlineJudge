#include <bits/stdc++.h>
using namespace std;
string num1,num2;
char oper;
int main(){
	cin >> num1 >> oper >> num2;
	if(num1.size() > num2.size())
	swap(num1, num2);

	if(oper == '+') num2[num2.size() - num1.size()] += num1[0] - '0';
	else{
		for(int i = 0; i < num1.size() - 1; ++i)
			num2.push_back('0');
	}
	cout << num2 << '\n';
}

// 설명
// 정수의 범위가 허용되는 자료형이 없기때문에 문자열로 해결해야한다.
// 왜 정답률이 50프로가 안되는지 의문이긴 하다.