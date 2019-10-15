#include <bits/stdc++.h>
using namespace std;
int main(){
    string item, body;
    int tc;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> tc;
    while(tc--){
        map<string, int> cloth;
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> item >> body;
            cloth[body]++;
        }
        int ans = 1;
        for(auto &next : cloth){
            ans *= (next.second + 1);
        }
        cout << ans - 1 << '\n';
    }
}