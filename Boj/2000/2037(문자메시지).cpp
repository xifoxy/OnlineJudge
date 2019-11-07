#include <bits/stdc++.h>
using namespace std;

string str;
int d[30]{1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int d2[30]{1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,6,7,7,7,8,8,8,8};
int main(){
    int n, m;
    cin >> n >> m;
    cin.ignore();
    getline(cin, str);

    int cnt = 0;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == ' ') {
            cnt += n;
            continue;
        }

        int cur = str[i] - 'A';
        cnt += (d[cur] * n);
        if(!i || str[i - 1] == ' ') continue;

        int bef = str[i - 1] - 'A';
        if(d2[cur] == d2[bef])
            cnt += m;
    }

    cout << cnt;
}

// 설명
// 친절한것 같으면서도 친절하지 않은 문제다.

// P는 누르는 시간
// W 같은 번호에 속한 알파벳을 연속으로 찍기 위한 시간( ex. AAA W가 3번 )
// 그리고 공백 문자를 연속으로 누를때는 기다릴 필요가 없다. 즉 누르는 시간만 포함된다는 뜻이다.
// 이거 3개만 잘 이해하고 구현하면 된다.