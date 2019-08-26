#include <bits/stdc++.h>
using namespace std;

string num;
const int M = 1e6 + 1;
bool visit[M];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int change;
    cin >> num >> change;

    queue<string> Q;
    Q.push(num);

    // ��ȯȽ�� ��ŭ Ž��
    while(change--){
        memset(visit, false, sizeof(visit));
        int sz = Q.size();

        // ť�� ũ�⸸ŭ ���ƾ� ��ȯȽ���� ������ �� �ִ�.
        for(int i = 0; i < sz; ++i){
            string temp = Q.front();
            Q.pop();

            int t_sz = temp.size();

            // ��ȯ ������ ��� ��츦 Ž���Ѵ�.
            for(int j = 0; j < t_sz; ++j){
                for(int k = j + 1; k < t_sz; ++k){
                    swap(temp[j], temp[k]);

                    // �ߺ��Ǵ� �κ��� ���ܿ�, 0���� �����ϴ� ���� �����Ѵ�.
                    if(!visit[stoi(temp)] && temp[0] != '0'){
                        visit[stoi(temp)] = true;
                        Q.push(temp);
                    }
                    swap(temp[j], temp[k]);
                }
            }
        }
    }

    int ans = -1;
    while(!Q.empty()){
        ans = max(stoi(Q.front()), ans);
        Q.pop();
    }
    cout << ans;
}

// ����(BFS, Recursion)
// ��ͷ� Ǯ�� BFS�� Ǯ�� ��ɷ� Ǯ� �������.
// ��ȯ ������ Ƚ����ŭ ��� ����� ���� ���Ͽ� ť�� �ְ� ū ���� ����ϸ� �ȴ�.